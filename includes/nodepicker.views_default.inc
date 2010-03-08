<?php
// $Id: nodepicker.views_default.inc,v 1.1 2010/03/08 12:15:01 blixxxa Exp $

/**
 * @file
 * Node Pickers's default views
 */

/**
 * Implementation of hook_views_default_views().
 */
function nodepicker_views_default_views() {
  $views = array();

  // Exported view: nodepicker_nodes
  $view = new view;
  $view->name = 'nodepicker_nodes';
  $view->description = '';
  $view->tag = 'Node Picker';
  $view->view_php = '';
  $view->base_table = 'node';
  $view->is_cacheable = FALSE;
  $view->api_version = 2;
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('fields', array(
    'title' => array(
      'label' => 'Title',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'strip_tags' => 0,
        'html' => 0,
      ),
      'link_to_node' => 0,
      'exclude' => 0,
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
      'relationship' => 'none',
    ),
    'type' => array(
      'label' => 'Type',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'strip_tags' => 0,
        'html' => 0,
      ),
      'link_to_node' => 0,
      'exclude' => 0,
      'id' => 'type',
      'table' => 'node',
      'field' => 'type',
      'relationship' => 'none',
    ),
    'status' => array(
      'label' => 'Published',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'strip_tags' => 0,
        'html' => 0,
      ),
      'type' => 'yes-no',
      'not' => 0,
      'exclude' => 0,
      'id' => 'status',
      'table' => 'node',
      'field' => 'status',
      'relationship' => 'none',
    ),
    'title_1' => array(
      'label' => 'Action',
      'alter' => array(
        'alter_text' => 1,
        'text' => 'Insert link',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'strip_tags' => 0,
        'html' => 0,
      ),
      'link_to_node' => 1,
      'exclude' => 0,
      'id' => 'title_1',
      'table' => 'node',
      'field' => 'title',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('sorts', array(
    'created' => array(
      'order' => 'DESC',
      'granularity' => 'second',
      'id' => 'created',
      'table' => 'node',
      'field' => 'created',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('filters', array(
    'title' => array(
      'operator' => 'contains',
      'value' => '',
      'group' => '0',
      'exposed' => TRUE,
      'expose' => array(
        'use_operator' => 0,
        'operator' => 'title_op',
        'identifier' => 'title',
        'label' => 'Title',
        'optional' => 1,
        'remember' => 0,
      ),
      'case' => 1,
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
      'relationship' => 'none',
    ),
    'type' => array(
      'operator' => 'in',
      'value' => array(),
      'group' => '0',
      'exposed' => TRUE,
      'expose' => array(
        'use_operator' => 0,
        'operator' => 'type_op',
        'identifier' => 'type',
        'label' => 'Type',
        'optional' => 1,
        'single' => 1,
        'remember' => 0,
        'reduce' => 0,
      ),
      'id' => 'type',
      'table' => 'node',
      'field' => 'type',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('access', array(
    'type' => 'role',
    'role' => array(
      '2' => 2,
    ),
  ));
  $handler->override_option('cache', array(
    'type' => 'none',
  ));
  $handler->override_option('title', 'Node picker nodes');
  $handler->override_option('header_format', '2');
  $handler->override_option('header_empty', 0);
  $handler->override_option('empty', '<p>No Results.</p>');
  $handler->override_option('empty_format', '2');
  $handler->override_option('use_pager', '1');
  $handler->override_option('style_plugin', 'table');
  $handler->override_option('style_options', array(
    'grouping' => '',
    'override' => 1,
    'sticky' => 0,
    'order' => 'asc',
    'columns' => array(
      'title' => 'title',
      'type' => 'type',
      'status' => 'status',
      'changed' => 'changed',
      'view_node' => 'view_node',
    ),
    'info' => array(
      'title' => array(
        'sortable' => 1,
        'separator' => '',
      ),
      'type' => array(
        'sortable' => 1,
        'separator' => '',
      ),
      'status' => array(
        'sortable' => 1,
        'separator' => '',
      ),
      'changed' => array(
        'sortable' => 1,
        'separator' => '',
      ),
      'view_node' => array(
        'separator' => '',
      ),
    ),
    'default' => 'title',
  ));

  $views[$view->name] = $view;
  
  //  Exported view: nodepicker_taxonomy
  $view = new view;
	$view->name = 'nodepicker_taxonomy';
	$view->description = '';
	$view->tag = 'Node Picker';
	$view->view_php = '';
	$view->base_table = 'term_data';
	$view->is_cacheable = FALSE;
	$view->api_version = 2;
	$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
	$handler = $view->new_display('default', 'Defaults', 'default');
	$handler->override_option('fields', array(
	  'name' => array(
	    'label' => 'Term',
	    'alter' => array(
	      'alter_text' => 0,
	      'text' => '',
	      'make_link' => 0,
	      'path' => '',
	      'link_class' => '',
	      'alt' => '',
	      'prefix' => '',
	      'suffix' => '',
	      'help' => '',
	      'trim' => 0,
	      'max_length' => '',
	      'word_boundary' => 1,
	      'ellipsis' => 1,
	      'strip_tags' => 0,
	      'html' => 0,
	    ),
	    'link_to_taxonomy' => 0,
	    'exclude' => 0,
	    'id' => 'name',
	    'table' => 'term_data',
	    'field' => 'name',
	    'relationship' => 'none',
	  ),
	  'name_1' => array(
	    'label' => 'Vocabulary',
	    'alter' => array(
	      'alter_text' => 0,
	      'text' => '',
	      'make_link' => 0,
	      'path' => '',
	      'link_class' => '',
	      'alt' => '',
	      'prefix' => '',
	      'suffix' => '',
	      'help' => '',
	      'trim' => 0,
	      'max_length' => '',
	      'word_boundary' => 1,
	      'ellipsis' => 1,
	      'strip_tags' => 0,
	      'html' => 0,
	    ),
	    'exclude' => 0,
	    'id' => 'name_1',
	    'table' => 'vocabulary',
	    'field' => 'name',
	    'relationship' => 'none',
	  ),
	  'name_2' => array(
	    'label' => 'Action',
	    'alter' => array(
	      'alter_text' => 1,
	      'text' => 'Insert link',
	      'make_link' => 0,
	      'path' => '',
	      'link_class' => '',
	      'alt' => '',
	      'prefix' => '',
	      'suffix' => '',
	      'help' => '',
	      'trim' => 0,
	      'max_length' => '',
	      'word_boundary' => 1,
	      'ellipsis' => 1,
	      'strip_tags' => 0,
	      'html' => 0,
	    ),
	    'link_to_taxonomy' => 1,
	    'exclude' => 0,
	    'id' => 'name_2',
	    'table' => 'term_data',
	    'field' => 'name',
	    'relationship' => 'none',
	  ),
	));
	$handler->override_option('sorts', array(
	  'name' => array(
	    'order' => 'ASC',
	    'id' => 'name',
	    'table' => 'term_data',
	    'field' => 'name',
	    'relationship' => 'none',
	  ),
	));
	$handler->override_option('filters', array(
	  'vid' => array(
	    'operator' => 'in',
	    'value' => array(),
	    'group' => '0',
	    'exposed' => TRUE,
	    'expose' => array(
	      'use_operator' => 0,
	      'operator' => 'vid_op',
	      'identifier' => 'vid',
	      'label' => 'Vocabulary',
	      'optional' => 1,
	      'single' => 1,
	      'remember' => 0,
	      'reduce' => 0,
	    ),
	    'id' => 'vid',
	    'table' => 'term_data',
	    'field' => 'vid',
	    'relationship' => 'none',
	  ),
	));
	$handler->override_option('access', array(
	  'type' => 'none',
	));
	$handler->override_option('cache', array(
	  'type' => 'none',
	));
	$handler->override_option('title', 'Node picker taxonomy');
	$handler->override_option('use_pager', '1');
	$handler->override_option('style_plugin', 'table');
	$handler->override_option('style_options', array(
	  'grouping' => '',
	  'override' => 1,
	  'sticky' => 0,
	  'order' => 'asc',
	  'columns' => array(
	    'name' => 'name',
	    'name_1' => 'name_1',
	    'description' => 'description',
	    'name_2' => 'name_2',
	  ),
	  'info' => array(
	    'name' => array(
	      'sortable' => 1,
	      'separator' => '',
	    ),
	    'name_1' => array(
	      'sortable' => 1,
	      'separator' => '',
	    ),
	    'description' => array(
	      'separator' => '',
	    ),
	    'name_2' => array(
	      'sortable' => 0,
	      'separator' => '',
	    ),
	  ),
	  'default' => 'name',
	));

	$views[$view->name] = $view;

  return $views;
}