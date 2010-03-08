// $Id: nodepicker.js,v 1.1 2010/03/08 12:15:01 blixxxa Exp $

/**
 * @file nodepicker.js
 *
 * All the javascript to make Node Picker work.
 */

/**
 * Insert link into WYSIWYG editor.
 */
function nodepicker_insert(href, title)
{
  // Get WYSIWYG editor instance.
  var instanceId = parent.instanceId;
  
  // Get editor name.
  var editor = parent.Drupal.wysiwyg.instances[instanceId].editor;
  
  // Get selection if one exists.
  var content = nodepicker_selection(instanceId, editor);
  
  // If no selection exists, use title.
  if(content.length == 0) {
    content = title;
  }
  
  // Insert tag.
  var $node;
  switch(editor) {
    case "tinymce":
      $node = $(parent.tinyMCE.activeEditor.selection.getNode());
    break;
    
    case "fckeditor":
      var selection = nodepicker_fckeditor_selection(instanceId);
      $node = $(selection.anchorNode.parentNode);
    break;
  }
  
  // Update link if cursor inside anchor tag.
  if($node[0].nodeName == "A") {
    $node.replaceWith('<a class="nodepicker-link" href="'+href+'" title="'+$node.attr("title")+'">'+$node.text()+'</a>');
  }
  else {
    parent.Drupal.wysiwyg.instances[instanceId].insert('<a class="nodepicker-link" title="'+title+'" href="'+href+'">'+content+'</a>');
  }
  
  // Close jQuery UI dialog.
  parent.nodepicker_dialog_close();
}

/**
 * Get WYSIWYG editor selection.
 */
function nodepicker_selection(instanceId, editor) {
  // Get editor name.
  var editor = parent.Drupal.wysiwyg.instances[instanceId].editor;
  
  // Init content variable.
  var content = '';
  
  // Get text selection if one exists.
  switch(editor) {
    case "tinymce":
      content = parent.tinyMCE.activeEditor.selection.getContent();
    break;
    
    case "fckeditor":
      var selection = nodepicker_fckeditor_selection(instanceId);
      if(selection.createRange) {
        content = selection.createRange().text;
      }
      else {
        content = selection.toString();
      }
    break;
  }
  
  return content;
}

/**
 * Get FCKEditor selection.
 */
function nodepicker_fckeditor_selection(instanceId) {
  var fckeditor = parent.FCKeditorAPI.GetInstance(instanceId);
  var selection = (fckeditor.EditorWindow.getSelection ? fckeditor.EditorWindow.getSelection() : fckeditor.EditorDocument.selection);
  return selection;
}

/**
 * Make things happen on page load.
 */
Drupal.behaviors.nodepicker = function(context) {
  // Fade in page.
  $(".page").fadeIn();
  
  // Add on click function for buttons.
  $(".header a.button").click(function(){
    $(".page").fadeOut("normal", function(){
      $(this).remove();
      $("#content").load($(this).attr("href"));
    });
  });
  
  // Add on click function for link select.
  $("a.nodepicker-insert").click(function(){
    $self = $(this);
    nodepicker_insert($self.attr("href"), $self.attr("title"));
    return false;
  });
    
  // Display messages if available.
  if(!$("#messages:not(:has(*))").length) {
    $("#messages").fadeIn();
    setTimeout(function() {
      $("#messages").fadeOut('slow', function() {
        $("#messages").html('');
      });
    }, 2000);
  }
}