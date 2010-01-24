<?php

/**
 * Implementation of hook_content_default_fields().
 */
function cyoaexample_content_default_fields() {
  module_load_include('inc', 'cyoaexample', 'cyoaexample.defaults');
  $args = func_get_args();
  return call_user_func_array('_cyoaexample_content_default_fields', $args);
}

/**
 * Implementation of hook_node_info().
 */
function cyoaexample_node_info() {
  module_load_include('inc', 'cyoaexample', 'cyoaexample.features.node');
  $args = func_get_args();
  return call_user_func_array('_cyoaexample_node_info', $args);
}

/**
 * Implementation of hook_views_default_views().
 */
function cyoaexample_views_default_views() {
  module_load_include('inc', 'cyoaexample', 'cyoaexample.features.views');
  $args = func_get_args();
  return call_user_func_array('_cyoaexample_views_default_views', $args);
}
