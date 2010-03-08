<?php // $Id: nodepicker-nodes.tpl.php,v 1.1 2010/03/08 12:15:02 blixxxa Exp $ ?>
<div class="page" id="page-nodes">
  <div class="header">
    <h2><?php print t('Nodes') ?></h2>
    <a href="<?php print url('nodepicker/taxonomy') ?>" class="button" id="taxonomy-button"><?php print t('Taxonomy'); ?></a>
    <a href="<?php print url('nodepicker/menu') ?>" class="button" id="menu-button"><?php print t('Menu'); ?></a>
  </div>
  <div id="browse">
    <div class="browse">
      <?php print $content; ?>
    </div>
  </div>
</div>