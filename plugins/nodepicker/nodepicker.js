// $Id: nodepicker.js,v 1.1 2010/03/08 12:15:02 blixxxa Exp $

var instanceId = null;

/**
 * Define WYSIWYG API plugin.
 */
Drupal.wysiwyg.plugins.nodepicker = {

  /**
   * Return whether the passed node belongs to this plugin.
   */
  isNode: function(node) {
    return ($(node).is('a.nodepicker'));
  },

  /**
   * Execute the button.
   */
  invoke: function(data, settings, instanceId) {
    if (data.format == 'html') {
      nodepicker_dialog_open(instanceId);
    }
  },

  /**
   * Replace all [nodepicker] tags with links.
   * FID == Image Preset == Link Preset == Link Target == Styles
   */
  attach: function(content, settings, instanceId) {
    content = content.replace(/\[ibimage\=\=([^\[\]]+)\]/g, function(orig, match) {
      var node = {}
      return nodepicker_decode(match, node);
    });
    return content;
  },

  /**
   * Replace links with [nodepicker] tags in content upon detaching editor.
   */
  detach: function(content, settings, instanceId) {
    var $content = $('<div>' + content + '</div>'); // No .outerHTML() in jQuery :(
    $('a.nodepicker', $content).each(function(node) {
      var data = this.title.split("==");
      var inlineTag = '[nodepicker==' + data[0] + '==' + data[1] + '==' + data[2] + '==' + data[3] + '==' + data[4] + ']';
      $(this).replaceWith(inlineTag);
    });
    return $content.html();
  }
};

/**
 * Open jQuery UI dialog box.
 */
function nodepicker_dialog_open(instance) {
  instanceId = instance;
  $("body").append("<div id='nodepicker_dialog'><iframe id='nodepicker_dialog_contents' src='"+Drupal.settings.nodepicker.basepath + "?q=nodepicker/nodes' width='602' height='446' frameborder='0' /></div>");
  $("#nodepicker_dialog").dialog({ modal: true, height: 476, width: 602, title: Drupal.t('Node Picker'), beforeclose: function(event, ui) { nodepicker_dialog_close(); } }).show();
}

/**
 * Close jQuery UI dialog box.
 */
function nodepicker_dialog_close() {
  $("#nodepicker_dialog").remove();
}

/**
 * Decode an [nodepicker] tag and wait for response.
 */
function nodepicker_decode(tag, node) {
  var ibdata = null;
  $.ajax({
      type: "POST",
      url: Drupal.settings.basePath + 'index.php?q=imagebrowser/ajax&tag=[ibimage==' + tag + ']',
      contentType: "application/json; charset=utf-8",
      dataType: "json",
      data: {},
      cache: true,
      async: false,
      success: function(data, textStatus) {
        ibdata = data;
      }
  });
  node.alt = ibdata.link_preset;
  node.target = ibdata.link_target;
  node['class'] = ibdata.styles;
  return '<img src="'+ibdata.image_url+'" alt="IB Image" title="'+ibdata.fid+'=='+ibdata.preset+'=='+ibdata.link_preset+'=='+ibdata.link_target+'=='+ibdata.styles+'" class="ibimage '+ibdata.styles+'" />';
}