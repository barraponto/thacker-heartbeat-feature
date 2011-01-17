<?php

/**
 * Implementation of hook_heartbeat_message_info().
 */
function thacker_heartbeat_heartbeat_message_info() {
  $messages = array();

  // Exported heartbeat message: heartbeat_new_user
  $messages[] = array (
    'message' => '!username has signed up for !sitename.',
    'message_concat' => '',
    'message_id' => 'heartbeat_new_user',
    'concat_args' => 
    array (
      'type' => 'single',
      'group_by' => 'none',
      'group_target' => '',
      'group_by_target' => '',
      'group_num_max' => '',
      'merge_separator' => '',
      'merge_end_separator' => '',
      'roles' => 
      array (
        0 => '0',
        1 => '0',
        2 => '0',
      ),
    ),
    'description' => 'New User message',
    'perms' => '1',
    'custom' => 1,
    'variables' => 
    array (
    ),
  );

  // Exported heartbeat message: heartbeat_joins_group
  $messages[] = array (
    'message' => '!username has joined !nodetype !nodetitle.',
    'message_concat' => '!username has joined !nodetype %nodetitle%.',
    'message_id' => 'heartbeat_joins_group',
    'concat_args' => 
    array (
      'type' => 'summary',
      'group_by' => 'user',
      'group_target' => 'node-title',
      'group_by_target' => '',
      'group_num_max' => '',
      'merge_separator' => ',',
      'merge_end_separator' => 'and',
      'roles' => 
      array (
        0 => '0',
        1 => '0',
        2 => '0',
      ),
    ),
    'description' => 'User subscribed to a group Message.',
    'perms' => '1',
    'custom' => 1,
    'variables' => 
    array (
    ),
  );


  return $messages;
}
