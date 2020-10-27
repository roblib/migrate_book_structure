<?php

function migrate_book_structure_drush_command() {

  $items['migrate-book-structure-post-migrate-book-hierarchy'] = array(
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
    'aliases' => array('mbspbh'),
  );

  $items['migrate-book-structure-post-migrate-internal-links'] = array(
    'description' => 'Update internal links in body fields.',
    'arguments' => array(
    ),
    'options' => array(
      'migration' => 'Machine name of migration to repair.',
      'dbconnection' => 'Source database connection in settings.php',
      'types' => 'Comma-separated list of content type machine names',
      'dry-run' => 'Set to TRUE to display changes to be made without writing to the database',
    ),
    'drupal dependencies' => array('migrate'),
    'aliases' => array('mbspil'),
  );

  $items['migrate-book-structure-post-migrate-image-urls'] = array(
    'description' => 'Update image tag src URLs of migrated files in body fields.',
    'arguments' => array(
    ),
    'options' => array(
      'migration' => 'Machine name of migration to repair.',
      'filemigration' => 'Machine name of file migration, if different from node migration id.',
      'dbconnection' => 'Source database connection in settings.php',
      'types' => 'Comma-separated list of content type machine names',
      'dry-run' => 'Set to TRUE to display changes to be made without writing to the database',
      'node' => 'Run in single node.',
    ),
    'drupal dependencies' => array('migrate'),
    'aliases' => array('mbspiu'),
  );

  $items['migrate-book-structure-get-tags-in-body'] = array(
    'description' => 'Export all HTML elements of the given tag from body and summary content',
    'arguments' => array(
    ),
    'options' => array(
      'types' => 'Comma-separated list of content type machine names',
      'tag' => 'Tag to extract.',
      'node' => 'Run in single node.',
    ),
    'aliases' => array('mbsgtb'),
  );

  return $items;
}