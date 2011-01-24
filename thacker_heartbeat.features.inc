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
      'hrule_add_page' => array(
        '#type' => array(
          '0' => 'rule',
          '1' => 'rule',
          '2' => 'rule',
          '3' => 'rule',
        ),
        '#set' => array(
          '0' => 'event_node_insert',
          '1' => 'event_node_insert',
          '2' => 'event_node_insert',
          '3' => 'event_node_insert',
        ),
        '#label' => array(
          '0' => 'Heartbeat: when user adds a page, log user activity',
          '1' => 'Heartbeat: when user adds a page, log user activity',
          '2' => 'Heartbeat: when user adds a page, log user activity',
          '3' => 'Heartbeat: when user adds a page, log user activity',
        ),
        '#active' => array(
          '0' => 1,
          '1' => 1,
          '2' => 1,
          '3' => 1,
        ),
        '#weight' => array(
          '0' => '0',
          '1' => '0',
          '2' => '0',
          '3' => '0',
        ),
        '#categories' => array(
          '0' => 'heartbeat',
          '1' => 'heartbeat',
          '2' => 'heartbeat',
          'thacker_heartbeat' => 'thacker_heartbeat',
          '3' => 'heartbeat',
        ),
        '#status' => 'default',
        '#conditions' => array(
          '0' => array(
            '#type' => 'condition',
            '#settings' => array(
              '#argument map' => array(
                'node' => 'node',
              ),
            ),
            '#name' => 'rules_condition_content_is_published',
            '#info' => array(
              'label' => 'page is published',
              'label callback' => FALSE,
              'arguments' => array(
                'node' => array(
                  'type' => 'node',
                  'label' => 'Content',
                ),
              ),
              'module' => 'Node',
            ),
            '#weight' => 0,
          ),
          '1' => array(
            '#weight' => 0,
            '#info' => array(
              'label' => 'Content has type page',
              'label callback' => FALSE,
              'arguments' => array(
                'node' => array(
                  'type' => 'node',
                  'label' => 'Content',
                ),
              ),
              'module' => 'Node',
            ),
            '#name' => 'rules_condition_content_is_type',
            '#settings' => array(
              'type' => array(
                'page' => 'page',
              ),
              '#argument map' => array(
                'node' => 'node',
              ),
            ),
            '#type' => 'condition',
          ),
          '2' => array(
            '#type' => 'condition',
            '#settings' => array(
              '#argument map' => array(
                'node' => 'node',
              ),
            ),
            '#name' => 'rules_condition_content_is_published',
            '#info' => array(
              'label' => 'page is published',
              'label callback' => FALSE,
              'arguments' => array(
                'node' => array(
                  'type' => 'node',
                  'label' => 'Content',
                ),
              ),
              'module' => 'Node',
            ),
            '#weight' => 0,
          ),
          '3' => array(
            '#weight' => 0,
            '#info' => array(
              'label' => 'Content has type page',
              'label callback' => FALSE,
              'arguments' => array(
                'node' => array(
                  'type' => 'node',
                  'label' => 'Content',
                ),
              ),
              'module' => 'Node',
            ),
            '#name' => 'rules_condition_content_is_type',
            '#settings' => array(
              'type' => array(
                'page' => 'page',
              ),
              '#argument map' => array(
                'node' => 'node',
              ),
            ),
            '#type' => 'condition',
          ),
          '4' => array(
            '#type' => 'condition',
            '#settings' => array(
              '#argument map' => array(
                'node' => 'node',
              ),
            ),
            '#name' => 'rules_condition_content_is_published',
            '#info' => array(
              'label' => 'page is published',
              'label callback' => FALSE,
              'arguments' => array(
                'node' => array(
                  'type' => 'node',
                  'label' => 'Content',
                ),
              ),
              'module' => 'Node',
            ),
            '#weight' => 0,
          ),
          '5' => array(
            '#weight' => 0,
            '#info' => array(
              'label' => 'Content has type page',
              'label callback' => FALSE,
              'arguments' => array(
                'node' => array(
                  'type' => 'node',
                  'label' => 'Content',
                ),
              ),
              'module' => 'Node',
            ),
            '#name' => 'rules_condition_content_is_type',
            '#settings' => array(
              'type' => array(
                'page' => 'page',
              ),
              '#argument map' => array(
                'node' => 'node',
              ),
            ),
            '#type' => 'condition',
          ),
          '6' => array(
            '#type' => 'condition',
            '#settings' => array(
              '#argument map' => array(
                'node' => 'node',
              ),
            ),
            '#name' => 'rules_condition_content_is_published',
            '#info' => array(
              'label' => 'page is published',
              'label callback' => FALSE,
              'arguments' => array(
                'node' => array(
                  'type' => 'node',
                  'label' => 'Content',
                ),
              ),
              'module' => 'Node',
            ),
            '#weight' => 0,
          ),
          '7' => array(
            '#weight' => 0,
            '#info' => array(
              'label' => 'Content has type page',
              'label callback' => FALSE,
              'arguments' => array(
                'node' => array(
                  'type' => 'node',
                  'label' => 'Content',
                ),
              ),
              'module' => 'Node',
            ),
            '#name' => 'rules_condition_content_is_type',
            '#settings' => array(
              'type' => array(
                'page' => 'page',
              ),
              '#argument map' => array(
                'node' => 'node',
              ),
            ),
            '#type' => 'condition',
          ),
        ),
        '#actions' => array(
          '0' => array(
            '#weight' => 0,
            '#type' => 'action',
            '#settings' => array(
              'uid_param' => '[author:uid]',
              'uid_target_param' => '0',
              'nid_param' => '[node:nid]',
              'nid_target_param' => '',
              'message_id_param' => 'heartbeat_add_node',
              'variables_param' => '@username=|=[author:user-name-url]-|-@node_type=|=[node:type]-|-@node_title=|=[node:title-link]-|-@types=|=pages-|-',
              '#eval input' => array(
                'token_rules_input_evaluator' => array(
                  'uid_param' => array(
                    '0' => 'author',
                  ),
                  'nid_param' => array(
                    '0' => 'node',
                  ),
                  'variables_param' => array(
                    '0' => 'node',
                    '1' => 'author',
                  ),
                ),
              ),
            ),
            '#name' => 'heartbeat_rules_default_action',
            '#info' => array(
              'label' => 'Logs activity for single users adding a page',
              'label callback' => FALSE,
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
          ),
          '1' => array(
            '#weight' => 0,
            '#type' => 'action',
            '#settings' => array(
              'uid_param' => '[author:uid]',
              'uid_target_param' => '0',
              'nid_param' => '[node:nid]',
              'nid_target_param' => '',
              'message_id_param' => 'heartbeat_add_node',
              'variables_param' => '@username=|=[author:user-name-url]-|-@node_type=|=[node:type]-|-@node_title=|=[node:title-link]-|-@types=|=pages-|-',
              '#eval input' => array(
                'token_rules_input_evaluator' => array(
                  'uid_param' => array(
                    '0' => 'author',
                  ),
                  'nid_param' => array(
                    '0' => 'node',
                  ),
                  'variables_param' => array(
                    '0' => 'node',
                    '1' => 'author',
                  ),
                ),
              ),
            ),
            '#name' => 'heartbeat_rules_default_action',
            '#info' => array(
              'label' => 'Logs activity for single users adding a page',
              'label callback' => FALSE,
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
          ),
          '2' => array(
            '#weight' => 0,
            '#type' => 'action',
            '#settings' => array(
              'uid_param' => '[author:uid]',
              'uid_target_param' => '0',
              'nid_param' => '[node:nid]',
              'nid_target_param' => '',
              'message_id_param' => 'heartbeat_add_node',
              'variables_param' => '@username=|=[author:user-name-url]-|-@node_type=|=[node:type]-|-@node_title=|=[node:title-link]-|-@types=|=pages-|-',
              '#eval input' => array(
                'token_rules_input_evaluator' => array(
                  'uid_param' => array(
                    '0' => 'author',
                  ),
                  'nid_param' => array(
                    '0' => 'node',
                  ),
                  'variables_param' => array(
                    '0' => 'node',
                    '1' => 'author',
                  ),
                ),
              ),
            ),
            '#name' => 'heartbeat_rules_default_action',
            '#info' => array(
              'label' => 'Logs activity for single users adding a page',
              'label callback' => FALSE,
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
          ),
          '3' => array(
            '#weight' => 0,
            '#type' => 'action',
            '#settings' => array(
              'uid_param' => '[author:uid]',
              'uid_target_param' => '0',
              'nid_param' => '[node:nid]',
              'nid_target_param' => '',
              'message_id_param' => 'heartbeat_add_node',
              'variables_param' => '@username=|=[author:user-name-url]-|-@node_type=|=[node:type]-|-@node_title=|=[node:title-link]-|-@types=|=pages-|-',
              '#eval input' => array(
                'token_rules_input_evaluator' => array(
                  'uid_param' => array(
                    '0' => 'author',
                  ),
                  'nid_param' => array(
                    '0' => 'node',
                  ),
                  'variables_param' => array(
                    '0' => 'node',
                    '1' => 'author',
                  ),
                ),
              ),
            ),
            '#name' => 'heartbeat_rules_default_action',
            '#info' => array(
              'label' => 'Logs activity for single users adding a page',
              'label callback' => FALSE,
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
          ),
        ),
        '#version' => 6003,
      ),
      'hrules_add_comment' => array(
        '#type' => array(
          '0' => 'rule',
          '1' => 'rule',
          '2' => 'rule',
          '3' => 'rule',
        ),
        '#set' => array(
          '0' => 'event_comment_publish',
          '1' => 'event_comment_publish',
          '2' => 'event_comment_publish',
          '3' => 'event_comment_publish',
        ),
        '#label' => array(
          '0' => 'Heartbeat: When a user adds a comment',
          '1' => 'Heartbeat: When a user adds a comment',
          '2' => 'Heartbeat: When a user adds a comment',
          '3' => 'Heartbeat: When a user adds a comment',
        ),
        '#active' => array(
          '0' => 0,
          '1' => 0,
          '2' => 0,
          '3' => 0,
        ),
        '#weight' => array(
          '0' => '0',
          '1' => '0',
          '2' => '0',
          '3' => '0',
        ),
        '#categories' => array(
          '0' => 'heartbeat',
          '1' => 'heartbeat',
          '2' => 'heartbeat',
          'thacker_heartbeat' => 'thacker_heartbeat',
          '3' => 'heartbeat',
        ),
        '#status' => 'default',
        '#conditions' => array(),
        '#actions' => array(
          '0' => array(
            '#weight' => 0,
            '#info' => array(
              'label' => 'Logs user activity for single users',
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
              'uid_param' => '[comment_author:uid]',
              'uid_target_param' => '[node_author:uid]',
              'nid_param' => '[node:nid]',
              'nid_target_param' => '0',
              'message_id_param' => 'heartbeat_add_comment',
              'variables_param' => '@username=|=[comment_author:user-name-url]-|-@title=|=[node:title-link]-|-@comment=|=[comment:comment-body-raw]-|-',
              '#eval input' => array(
                'token_rules_input_evaluator' => array(
                  'uid_param' => array(
                    '0' => 'comment_author',
                  ),
                  'uid_target_param' => array(
                    '0' => 'node_author',
                  ),
                  'nid_param' => array(
                    '0' => 'node',
                  ),
                  'variables_param' => array(
                    '0' => 'comment',
                    '1' => 'comment_author',
                    '2' => 'node',
                  ),
                ),
              ),
            ),
            '#type' => 'action',
          ),
          '1' => array(
            '#weight' => 0,
            '#info' => array(
              'label' => 'Logs user activity for single users',
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
              'uid_param' => '[comment_author:uid]',
              'uid_target_param' => '[node_author:uid]',
              'nid_param' => '[node:nid]',
              'nid_target_param' => '0',
              'message_id_param' => 'heartbeat_add_comment',
              'variables_param' => '@username=|=[comment_author:user-name-url]-|-@title=|=[node:title-link]-|-@comment=|=[comment:comment-body-raw]-|-',
              '#eval input' => array(
                'token_rules_input_evaluator' => array(
                  'uid_param' => array(
                    '0' => 'comment_author',
                  ),
                  'uid_target_param' => array(
                    '0' => 'node_author',
                  ),
                  'nid_param' => array(
                    '0' => 'node',
                  ),
                  'variables_param' => array(
                    '0' => 'comment',
                    '1' => 'comment_author',
                    '2' => 'node',
                  ),
                ),
              ),
            ),
            '#type' => 'action',
          ),
          '2' => array(
            '#weight' => 0,
            '#info' => array(
              'label' => 'Logs user activity for single users',
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
              'uid_param' => '[comment_author:uid]',
              'uid_target_param' => '[node_author:uid]',
              'nid_param' => '[node:nid]',
              'nid_target_param' => '0',
              'message_id_param' => 'heartbeat_add_comment',
              'variables_param' => '@username=|=[comment_author:user-name-url]-|-@title=|=[node:title-link]-|-@comment=|=[comment:comment-body-raw]-|-',
              '#eval input' => array(
                'token_rules_input_evaluator' => array(
                  'uid_param' => array(
                    '0' => 'comment_author',
                  ),
                  'uid_target_param' => array(
                    '0' => 'node_author',
                  ),
                  'nid_param' => array(
                    '0' => 'node',
                  ),
                  'variables_param' => array(
                    '0' => 'comment',
                    '1' => 'comment_author',
                    '2' => 'node',
                  ),
                ),
              ),
            ),
            '#type' => 'action',
          ),
          '3' => array(
            '#weight' => 0,
            '#info' => array(
              'label' => 'Logs user activity for single users',
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
              'uid_param' => '[comment_author:uid]',
              'uid_target_param' => '[node_author:uid]',
              'nid_param' => '[node:nid]',
              'nid_target_param' => '0',
              'message_id_param' => 'heartbeat_add_comment',
              'variables_param' => '@username=|=[comment_author:user-name-url]-|-@title=|=[node:title-link]-|-@comment=|=[comment:comment-body-raw]-|-',
              '#eval input' => array(
                'token_rules_input_evaluator' => array(
                  'uid_param' => array(
                    '0' => 'comment_author',
                  ),
                  'uid_target_param' => array(
                    '0' => 'node_author',
                  ),
                  'nid_param' => array(
                    '0' => 'node',
                  ),
                  'variables_param' => array(
                    '0' => 'comment',
                    '1' => 'comment_author',
                    '2' => 'node',
                  ),
                ),
              ),
            ),
            '#type' => 'action',
          ),
        ),
        '#version' => 6003,
      ),
      'shout_rule_0' => array(
        '#type' => array(
          '0' => 'rule',
          '1' => 'rule',
          '2' => 'rule',
          '3' => 'rule',
        ),
        '#categories' => array(
          '0' => 'heartbeat',
          '1' => 'heartbeat',
          '2' => 'heartbeat',
          'thacker_heartbeat' => 'thacker_heartbeat',
          '3' => 'heartbeat',
        ),
        '#set' => array(
          '0' => 'event_shout_post',
          '1' => 'event_shout_post',
          '2' => 'event_shout_post',
          '3' => 'event_shout_post',
        ),
        '#label' => array(
          '0' => 'heartbeat: After shouting, log shout message',
          '1' => 'heartbeat: After shouting, log shout message',
          '2' => 'heartbeat: After shouting, log shout message',
          '3' => 'heartbeat: After shouting, log shout message',
        ),
        '#active' => array(
          '0' => 1,
          '1' => 1,
          '2' => 1,
          '3' => 1,
        ),
        '#weight' => array(
          '0' => '6',
          '1' => '6',
          '2' => '6',
          '3' => '6',
        ),
        '#status' => 'default',
        '#conditions' => array(),
        '#actions' => array(
          '0' => array(
            '#weight' => 0,
            '#type' => 'action',
            '#settings' => array(
              'uid_param' => '[user:uid]',
              'uid_target_param' => '0',
              'nid_param' => '',
              'nid_target_param' => '',
              'message_id_param' => 'heartbeat_shout',
              'variables_param' => '@user=|=[user:user-name-url]-|-@message=|=[shout:shout-body]-|-',
              '#eval input' => array(
                'token_rules_input_evaluator' => array(
                  'uid_param' => array(
                    '0' => 'user',
                  ),
                  'variables_param' => array(
                    '0' => 'user',
                    '1' => 'shout',
                  ),
                ),
              ),
            ),
            '#name' => 'heartbeat_rules_default_action',
            '#info' => array(
              'label' => 'Logs relational user activity',
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
          ),
          '1' => array(
            '#weight' => 0,
            '#type' => 'action',
            '#settings' => array(
              'uid_param' => '[user:uid]',
              'uid_target_param' => '0',
              'nid_param' => '',
              'nid_target_param' => '',
              'message_id_param' => 'heartbeat_shout',
              'variables_param' => '@user=|=[user:user-name-url]-|-@message=|=[shout:shout-body]-|-',
              '#eval input' => array(
                'token_rules_input_evaluator' => array(
                  'uid_param' => array(
                    '0' => 'user',
                  ),
                  'variables_param' => array(
                    '0' => 'user',
                    '1' => 'shout',
                  ),
                ),
              ),
            ),
            '#name' => 'heartbeat_rules_default_action',
            '#info' => array(
              'label' => 'Logs relational user activity',
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
          ),
          '2' => array(
            '#weight' => 0,
            '#type' => 'action',
            '#settings' => array(
              'uid_param' => '[user:uid]',
              'uid_target_param' => '0',
              'nid_param' => '',
              'nid_target_param' => '',
              'message_id_param' => 'heartbeat_shout',
              'variables_param' => '@user=|=[user:user-name-url]-|-@message=|=[shout:shout-body]-|-',
              '#eval input' => array(
                'token_rules_input_evaluator' => array(
                  'uid_param' => array(
                    '0' => 'user',
                  ),
                  'variables_param' => array(
                    '0' => 'user',
                    '1' => 'shout',
                  ),
                ),
              ),
            ),
            '#name' => 'heartbeat_rules_default_action',
            '#info' => array(
              'label' => 'Logs relational user activity',
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
          ),
          '3' => array(
            '#weight' => 0,
            '#type' => 'action',
            '#settings' => array(
              'uid_param' => '[user:uid]',
              'uid_target_param' => '0',
              'nid_param' => '',
              'nid_target_param' => '',
              'message_id_param' => 'heartbeat_shout',
              'variables_param' => '@user=|=[user:user-name-url]-|-@message=|=[shout:shout-body]-|-',
              '#eval input' => array(
                'token_rules_input_evaluator' => array(
                  'uid_param' => array(
                    '0' => 'user',
                  ),
                  'variables_param' => array(
                    '0' => 'user',
                    '1' => 'shout',
                  ),
                ),
              ),
            ),
            '#name' => 'heartbeat_rules_default_action',
            '#info' => array(
              'label' => 'Logs relational user activity',
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
          ),
        ),
        '#version' => 6003,
      ),
      'rules_heartbeat_when_user_signs_up_log_activity' => array(
        '#type' => 'rule',
        '#set' => 'event_user_insert',
        '#label' => 'Heartbeat: when user signs up, log activity',
        '#active' => 1,
        '#weight' => '0',
        '#categories' => array(
          '0' => 'heartbeat',
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
          '0' => 'heartbeat',
          '1' => 'og_activity',
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
      'og_activity_rules_1' => array(
        '#type' => array(
          '0' => 'rule',
          '1' => 'rule',
          '2' => 'rule',
          '3' => 'rule',
        ),
        '#set' => array(
          '0' => 'event_og_become_co_admin',
          '1' => 'event_og_become_co_admin',
          '2' => 'event_og_become_co_admin',
          '3' => 'event_og_become_co_admin',
        ),
        '#categories' => array(
          '0' => 'og_activity',
          '1' => 'heartbeat',
          'thacker_heartbeat' => 'thacker_heartbeat',
          '2' => 'og_activity',
          '3' => 'heartbeat',
          '4' => 'og_activity',
          '5' => 'heartbeat',
          '6' => 'og_activity',
          '7' => 'heartbeat',
        ),
        '#label' => array(
          '0' => 'User becomes co-admin of a group',
          '1' => 'User becomes co-admin of a group',
          '2' => 'User becomes co-admin of a group',
          '3' => 'User becomes co-admin of a group',
        ),
        '#active' => array(
          '0' => 0,
          '1' => 0,
          '2' => 0,
          '3' => 0,
        ),
        '#weight' => array(
          '0' => '0',
          '1' => '0',
          '2' => '0',
          '3' => '0',
        ),
        '#status' => 'default',
        '#conditions' => array(),
        '#actions' => array(
          '0' => array(
            '#weight' => 1,
            '#info' => array(
              'label' => 'Logs user activity for single users',
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
              'uid_param' => '[user:uid]',
              'uid_target_param' => '0',
              'nid_param' => '[node:nid]',
              'nid_target_param' => '[node:og-id]',
              'message_id_param' => 'og_become_co_admin',
              'variables_param' => '@username=|=[user:user-name-url]-|-@group=|=[node:title-link]-|-',
              '#eval input' => array(
                'token_rules_input_evaluator' => array(
                  'uid_param' => array(
                    '0' => 'user',
                  ),
                  'nid_param' => array(
                    '0' => 'node',
                  ),
                  'nid_target_param' => array(
                    '0' => 'node',
                  ),
                  'variables_param' => array(
                    '0' => 'node',
                    '1' => 'user',
                  ),
                ),
              ),
            ),
            '#type' => 'action',
          ),
          '1' => array(
            '#weight' => 1,
            '#info' => array(
              'label' => 'Logs user activity for single users',
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
              'uid_param' => '[user:uid]',
              'uid_target_param' => '0',
              'nid_param' => '[node:nid]',
              'nid_target_param' => '[node:og-id]',
              'message_id_param' => 'og_become_co_admin',
              'variables_param' => '@username=|=[user:user-name-url]-|-@group=|=[node:title-link]-|-',
              '#eval input' => array(
                'token_rules_input_evaluator' => array(
                  'uid_param' => array(
                    '0' => 'user',
                  ),
                  'nid_param' => array(
                    '0' => 'node',
                  ),
                  'nid_target_param' => array(
                    '0' => 'node',
                  ),
                  'variables_param' => array(
                    '0' => 'node',
                    '1' => 'user',
                  ),
                ),
              ),
            ),
            '#type' => 'action',
          ),
          '2' => array(
            '#weight' => 1,
            '#info' => array(
              'label' => 'Logs user activity for single users',
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
              'uid_param' => '[user:uid]',
              'uid_target_param' => '0',
              'nid_param' => '[node:nid]',
              'nid_target_param' => '[node:og-id]',
              'message_id_param' => 'og_become_co_admin',
              'variables_param' => '@username=|=[user:user-name-url]-|-@group=|=[node:title-link]-|-',
              '#eval input' => array(
                'token_rules_input_evaluator' => array(
                  'uid_param' => array(
                    '0' => 'user',
                  ),
                  'nid_param' => array(
                    '0' => 'node',
                  ),
                  'nid_target_param' => array(
                    '0' => 'node',
                  ),
                  'variables_param' => array(
                    '0' => 'node',
                    '1' => 'user',
                  ),
                ),
              ),
            ),
            '#type' => 'action',
          ),
          '3' => array(
            '#weight' => 1,
            '#info' => array(
              'label' => 'Logs user activity for single users',
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
              'uid_param' => '[user:uid]',
              'uid_target_param' => '0',
              'nid_param' => '[node:nid]',
              'nid_target_param' => '[node:og-id]',
              'message_id_param' => 'og_become_co_admin',
              'variables_param' => '@username=|=[user:user-name-url]-|-@group=|=[node:title-link]-|-',
              '#eval input' => array(
                'token_rules_input_evaluator' => array(
                  'uid_param' => array(
                    '0' => 'user',
                  ),
                  'nid_param' => array(
                    '0' => 'node',
                  ),
                  'nid_target_param' => array(
                    '0' => 'node',
                  ),
                  'variables_param' => array(
                    '0' => 'node',
                    '1' => 'user',
                  ),
                ),
              ),
            ),
            '#type' => 'action',
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
