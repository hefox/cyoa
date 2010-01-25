<?php

/**
 
 */
class views_handler_filter_cyoa_uid_hostname extends views_handler_filter_boolean_operator {
  function construct() {
    parent::construct();
    $this->value_value = t('Is the logged in user or annoymous hostname');
  }

  function query() {
    $this->ensure_my_table();
    $where = "$this->table_alias.$this->real_field ";
    global $user;
    if ($user->uid) {
      if (empty($this->value)) {
        $where .= '!= ***CURRENT_USER***';
      }
      else {
        $where .= '= ***CURRENT_USER***';
      }
      $this->query->add_where($this->options['group'], $where);    
    } else {
      if (empty($this->value)) {
         $where .= 'hostname != "%s"';
      }
      else {
        $where .= 'hostname = "%s"';
      }  
      $this->query->add_where($this->options['group'], $where, ip_address());    
    }
    
  }
}