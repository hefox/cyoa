<?php


/**
 * Implementation of hook_views_data().
 */
function cyoa_views_data() {
  $data = array();
  $data['cyoa']['table']['group']  = t('Cyoa');
  $data['cyoa']['cyoaid'] = array(
    'title' => t('Cyoaid'),
    'help' => t('The choice your own adventure ID.'), 
    // Information for accepting a nid as an argument
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
      'name field' => 'title', // the field to display in the summary.
      'numeric' => TRUE,
      'validate type' => 'cyoaid',
    ),
    // Information for accepting a nid as a filter
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    // Information for sorting on a nid.
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  /* //FIXME Completed is not in use yet. 
  $data['cyoa']['completed'] = array(
    'title'=> t('Completed'),
    'help' => t('Whether or not the adventure has been completed.'),
    'field' => array(
      'handler' => 'views_handler_field_boolean',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_boolean_operator',
      'label' => t('Completed'),
      'type' => 'yes-no',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  */
    /* auto join the cyoa table with the cyoac table */
    $data['cyoa']['table']['join'] = array(
    'cyoac' => array(
      'left_field' => 'cyoaid',
      'field' => 'cyoaid',
    ),
  ); 
  
  /*
   * Date adventure started
   */
  $data['cyoa']['timestamp'] = array(
    'title' => t('Date started'), // The item it appears as on the UI,
    'help' => t('The date the adventure started.'), // The help that appears on the UI,
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );
  /*
   * Hostname // FIXME TODO convert this to session_id?
   */
  $data['cyoa']['hostname'] = array(
    'title' => t('Hostname'),
    'help' => t('Hostname'),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
      'help' => t('Current hostname'),
    ),
  );

  /*
   *  cyoa_nid
   */
  $data['node']['cyoa_nid'] = array(
    'group' => t('Cyoa'),
    'title' => t('Cyoa node'),
    'real field' => 'nid',
    'help' => t('Create a relationship to a node cyoa.'),
    'relationship' => array(
      'handler' => 'views_handler_relationship',
      'base' => 'cyoa',
      'base field' => 'nid',
      'label' => t('Cyoa to node'),
      'relationship field' => 'nid',
    ),
  );

  $data['cyoa']['uid'] = array(
    'group' => t('Cyoa'),
    'title' => t('Cyoa user'),
    'help' => t('Create a relationship to a cyoa.'),
    'relationship' => array(
      'handler' => 'views_handler_relationship',
      'base' => 'users',
      'base field' => 'uid',
      'label' => t('Cyoa to user'),
    ),
  );
  $data['cyoa']['uid_hostname'] = array(
  'real field' => 'uid',
    'title' => t('Current user or hostname '),
    'help' => t('Filter by current username or hostname .'),
    'filter' => array(
      'handler' => 'views_handler_filter_cyoa_uid_hostname',
      'type' => 'yes-no',
    ),
  );  
  
  $data['cyoac']['table']['join'] = array(
    'node' => array(
      'left_field' => 'nid',
      'field' => 'nid',
    ),
  ); 
  $data['cyoac']['timestamp'] = array(
    'title' => t('Date path aken'), // The item it appears as on the UI,
    'help' => t('The date the adventure started.'), // The help that appears on the UI,
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );

  $data['cyoac']['table']['group']  = t('Cyoa choices');
  $data['cyoac']['cyoacid'] = array(
    'title' => t('Cyoacid'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'help' => t('The choice your own adventure choice ID.'), // The help that appears on the UI,
    // Information for accepting a nid as an argument
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
      'name field' => 'title', // the field to display in the summary.
      'numeric' => TRUE,
    ),
    // Information for accepting a nid as a filter
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    // Information for sorting on a nid.
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'relationship' => array(
      'handler' => 'views_handler_relationship',
      'base' => 'cyoa',
      'base field' => 'cyoaid',
      'label' => t('Cyoa to adventure'),
      'relationship field' => 'cyoaid',
    ),
  );
  $data['cyoac']['cyoaid'] = array(
    'title' => t('Choice\'s Cyoaid'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'help' => t('The choice your own adventure ID for the choice.'), // The help that appears on the UI,
    // Information for accepting a nid as an argument
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
      'name field' => 'title', // the field to display in the summary.
      'numeric' => TRUE,
    ),
    // Information for accepting a nid as a filter
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    // Information for sorting on a nid.
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['cyoac']['pcyoacid'] = array(
    'title' => t('Parent Cyoacid'),
    'help' => t('The choice your own adventure parent choice ID.'), // The help that appears on the UI,
    // Information for accepting a nid as an argument
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
      'name field' => 'title', // the field to display in the summary.
      'numeric' => TRUE,
    ),
    // Information for accepting a nid as a filter
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    // Information for sorting on a nid.
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  return $data;
}


/**
 * Implementation of hook_views_data().
 */
function cyoa_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'cyoa') ,
    ),
    'handlers' => array(
      'views_handler_filter_cyoa_uid_hostname' => array(
        'parent' => 'views_handler_filter_boolean_operator',
      ),
    )
  );
}