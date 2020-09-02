<?php

function migrate_islandnarratives_drush_command() {

  $items['migrate-islandnarratives-post-migrate-book-hierarchy'] = array(
    'description' => 'Import book hierarchy from legacy database.',
    'arguments' => array(
    ),
    'options' => array(
      'migration' => 'Machine name of migration to repair.',
      'dbconnection' => 'Source database connection in settings.php',
      'types' => 'Comma-separated list of content type machine names',
      'dry-run' => 'Set to TRUE to show changes to be made without altering the target database',
    ),
    'drupal dependencies' => array('migrate', 'book'),
    'aliases' => array('minpbh'),
  );

  $items['migrate-islandnarratives-post-migrate-internal-links'] = array(
    'description' => 'Update internal links in body fields.',
    'arguments' => array(
    ),
    'options' => array(
      'migration' => 'Machine name of migration to repair.',
      'types' => 'Comma-separated list of content type machine names',
      'dry-run' => 'Set to TRUE to display changes to be made without writing to the database',
    ),
    'drupal dependencies' => array('migrate'),
    'aliases' => array('minpil'),
  );


  return $items;

}