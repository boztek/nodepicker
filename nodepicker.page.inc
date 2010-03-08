<?php
// $Id: nodepicker.page.inc,v 1.1 2010/03/08 12:08:53 blixxxa Exp $

/**
 * Node Picker UI powered by Views.
 */
function nodepicker_page($page) {
  // Add styles.
  drupal_add_css(drupal_get_path('module', 'nodepicker') .'/theme/nodepicker.css');
  
  // Set styles.
  $styles = drupal_get_css();
  
  // Add javascript.
  drupal_add_js(drupal_get_path('module', 'views') .'/js/base.js');
  drupal_add_js(drupal_get_path('module', 'views') .'/js/ajax_view.js');
  drupal_add_js(drupal_get_path('module', 'nodepicker') .'/js/nodepicker.js');
  
  // Theme content.
  switch($page) {
    case 'menu':
      $content = theme('nodepicker_menu');
    break;
    
    case 'taxonomy':
      $content = theme('nodepicker_taxonomy');
    break;
    
    default:
      $content = theme('nodepicker_nodes');
    break;
  }

  // Set messages.
  $messages = theme('status_messages');
  
  // Set scripts.
  $scripts = drupal_get_js();
  
  // Theme the output.
  print theme('nodepicker_page',
    $styles,
    $messages,
    $content,
    $scripts
  );
  
  exit();
}