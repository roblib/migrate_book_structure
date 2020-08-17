<?php

/**
 * @file
 *
 * Migrate classes for Island Narratives.
 */

function migrate_islandnarratives_migrate_api() {

  // Specify the DB connection and the source Drupal version.
  $common_arguments = array(
    'source_connection' => 'cap',
    'source_version' => 6,
    'group_name' => 'islandnarratives',
  );


  $api = array(
    'api' => 2,
    'groups' => array(
      'islandnarratives' => array(
        'title' => t('Island Narratives'),
      ),
    ),
  );

  $api['migrations']['IslandNarrativesRegion'] = $common_arguments + array(

      'class_name' => 'DrupalTerm6Migration',
      'description' => t('Migration of Region terms'),
      'source_vocabulary' => '1', // D6 Vocabulary ID
      'destination_vocabulary' => 'region',
      'group_name' => 'islandnarratives',


  );
    /*
    'IslandNarrativesFile' => array(
      'class_name' => 'DrupalFile6Migration',
      'description' => t('Import Drupal 6 files'),
      'user_migration' => 'ExampleUser',
      'default_uid' => 1,
      'source_dir' => 'http://vre2.upei.ca/cap',
      'destination_dir' => 'public://islandnarratives_files',
    ),
    'IslandNarrativesBookPage' => array(
      'class_name' => 'IslandNarrativesBookPageMigration',
      'group_name' => 'islandnarratives',
    ),
    'IslandNarrativesFile' => array(
      'class_name' => 'IslandNarrativesFile',
      'group_name' => 'islandnarratives',
    ),*/




  return $api;
}
