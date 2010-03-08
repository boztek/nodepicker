<?php // $Id: nodepicker-menu.tpl.php,v 1.1 2010/03/08 12:15:02 blixxxa Exp $ ?>
<div class="page" id="page-menu">
  <div class="header">
    <h2><?php print t('Menu') ?></h2>
    <a href="<?php print url('nodepicker/taxonomy') ?>" class="button" id="taxonomy-button"><?php print t('Taxonomy'); ?></a>
    <a href="<?php print url('nodepicker/nodes') ?>" class="button" id="nodes-button"><?php print t('Nodes'); ?></a>
  </div>
  <div id="browse">
    <div class="browse">
      <?php print $content; ?>
    </div>
  </div>
</div>