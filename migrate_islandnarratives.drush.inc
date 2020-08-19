<?php

function migrate_islandnarratives_drush_command() {

  $items['migrate-islandnarratives-post-migrate-book-hierarchy'] = array(
    'description' => 'Import book hierarchy from legacy database.',
    'arguments' => array(
      'migration' => 'Legacy database connection name. (Defined in settings.php $databases.)',
    ),
    'drupal dependencies' => array('migrate', 'book'),
    'aliases' => array('minpbh'),
  );

  return $items;

}