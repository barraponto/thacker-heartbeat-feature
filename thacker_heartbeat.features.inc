<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function thacker_heartbeat_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_heartbeat_message_info().
 */
function thacker_heartbeat_heartbeat_message_info() {
  $messages = array();

  // Exported heartbeat message: heartbeat_new_user
  $messages['heartbeat_new_user'] = array (
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
      'merge_separator_t' => '0',
      'merge_end_separator_t' => '0',
    ),
    'description' => 'New User message',
    'perms' => '1',
    'custom' => 1,
    'variables' => 
    array (
    ),
  );

  // Exported heartbeat message: heartbeat_joins_group
  $messages['heartbeat_joins_group'] = array (
    'message' => '!username has joined !nodetype !nodetitle.',
    'message_concat' => '!username has joined !nodetype %nodetitle%.',
    'message_id' => 'heartbeat_joins_group',
    'concat_args' => 
    array (
      'type' => 'summary',
      'group_by' => 'node',
      'group_target' => '',
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
      'merge_separator_t' => '0',
      'merge_end_separator_t' => '1',
    ),
    'description' => '',
    'perms' => '1',
    'custom' => 1,
    'variables' => 
    array (
    ),
  );


  return $messages;
}

/**
 * Implementation of hook_rules_defaults().
 */
function thacker_heartbeat_rules_defaults() {
  return array(
    'rules' => array(
      'rules_heartbeat_when_user_signs_up_log_activity' => array(
        '#type' => 'rule',
        '#set' => 'event_user_insert',
        '#label' => 'Heartbeat: when user signs up, log activity',
        '#active' => 1,
        '#weight' => '0',
        '#categories' => array(
          'thacker_heartbeat' => 'thacker_heartbeat',
        ),
        '#status' => 'default',
        '#conditions' => array(),
        '#actions' => array(
          '0' => array(
            '#weight' => 0,
            '#info' => array(
              'label' => 'Logs default activity',
              'eval input' => array(
                '0' => 'uid_param',
                '1' => 'uid_target_param',
                '2' => 'nid_param',
                '3' => 'nid_target_param',
                '4' => 'message_id_param',
                '5' => 'variables_param',
              ),
              'module' => 'heartbeat',
            ),
            '#name' => 'heartbeat_rules_default_action',
            '#settings' => array(
              'uid_param' => '',
              'uid_target_param' => '',
              'nid_param' => '',
              'nid_target_param' => '',
              'message_id_param' => 'heartbeat_new_user',
              'variables_param' => '@username=|=[user:realname]-|-@sitename=|=site-|-',
              '#eval input' => array(
                'token_rules_input_evaluator' => array(
                  'variables_param' => array(
                    '0' => 'user',
                  ),
                ),
              ),
            ),
            '#type' => 'action',
          ),
        ),
        '#version' => 6003,
      ),
      'rules_heartbeat_when_user_subscribes_to_a_group_log_activity' => array(
        '#type' => 'rule',
        '#set' => 'event_og_user_insert',
        '#label' => 'Heartbeat: when user subscribes to a group, log activity',
        '#active' => 1,
        '#weight' => '0',
        '#categories' => array(
          'thacker_heartbeat' => 'thacker_heartbeat',
        ),
        '#status' => 'default',
        '#conditions' => array(),
        '#actions' => array(
          '0' => array(
            '#info' => array(
              'label' => 'Logs default activity',
              'eval input' => array(
                '0' => 'uid_param',
                '1' => 'uid_target_param',
                '2' => 'nid_param',
                '3' => 'nid_target_param',
                '4' => 'message_id_param',
                '5' => 'variables_param',
              ),
              'module' => 'heartbeat',
            ),
            '#name' => 'heartbeat_rules_default_action',
            '#settings' => array(
              'uid_param' => '',
              'uid_target_param' => '',
              'nid_param' => '',
              'nid_target_param' => '',
              'message_id_param' => 'heartbeat_joins_group',
              'variables_param' => '@username=|=[user:realname]-|-@nodetype=|=[group:type]-|-@nodetitle=|=[group:title-raw]-|-',
              '#eval input' => array(
                'token_rules_input_evaluator' => array(
                  'variables_param' => array(
                    '0' => 'group',
                    '1' => 'user',
                  ),
                ),
              ),
            ),
            '#type' => 'action',
            '#weight' => 0,
          ),
        ),
        '#version' => 6003,
      ),
    ),
  );
}

/**
 * Implementation of hook_views_api().
 */
function thacker_heartbeat_views_api() {
  return array(
    'api' => '2',
  );
}
