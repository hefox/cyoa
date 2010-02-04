<?php

/**
 * FIXME the logic is still a bit wonky atm here
 */
class views_handler_filter_cyoa_uid_hostname extends views_handler_filter_boolean_operator {
  function construct() {
    parent::construct();
    $this->value_value = t('Is the logged in user or annoymous hostname');
  }

  function query() {
    $this->ensure_my_table();
    
    global $user;
    if ($user->uid) {
     $where = "$this->table_alias.$this->real_field ";
      if (empty($this->value)) {
        $where .= '!= ***CURRENT_USER***';
      }
      else {
        $where .= '= ***CURRENT_USER***';
      }
      $this->query->add_where($this->options['group'], $where);    
    } else {
      $where = "$this->table_alias.";
      if (empty($this->value)) {
         $where .= 'hostname != "%s"';
      }
      else {
        $where .= 'hostname = "%s" AND ' . "$this->table_alias.$this->real_field = 0";
      }  
      $this->query->add_where($this->options['group'], $where, ip_address());    
    }
    
  }
}