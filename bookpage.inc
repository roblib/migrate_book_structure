<?php

/**
 * @file article.inc
 * Article nodes migration from drupal 6 to 7.
 */

class IslandNarrativesBookPageMigration extends DrupalNode6Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);


    $body_arguments = MigrateTextFieldHandler::arguments(array('source_field' => 'teaser'), array('source_field' => 'format'), NULL);


    $this->addFieldMapping('body', 'body')->arguments($body_arguments);
    $this->addFieldMapping('language')->defaultValue('en');
    $this->addFieldMapping('is_new')->defaultValue(TRUE);
  }

  /**
   * Overrides parent::query to add more data to the source, in our case,
   * book hierarchy stuff.
   */
  public function query() {
    $query = parent::query();
    // Add in book parent child relationships.
    $query->join('book', 'b', 'n.nid = b.nid');
    $query->addField('b', 'bid', 'book_id');
    $query->join('menu_links', 'ml', 'b.mlid = ml.mlid');
    $query->addField('ml', 'weight', 'book_weight');
    return $query;
  }

  /**
   * Acts right after a book node has been saved. Map the book hierarchy.
   *
   * @param object $node
   *   A node object for the newly migrated book.
   * @param stdClass $row
   *   An object representing data from the source row.
   */
  public function complete($node, stdClass $row) {
    // If this is a top-level book, don't set a parent.
    $book_id = $row->nid == $row->book_id ? $node->nid : $this->lookupMigratedBook($row->book_id);
    // Book id - effectively, parent nid.
    $node->book['bid'] = $book_id;
    $node->book['nid'] = $node->nid;
    $node->book['weight'] = $row->book_weight;
    _book_update_outline($node);
    node_save($node);
  }

  /**
   * Returns a mapping for a migrated book.
   *
   * @param int $source_book_nid
   *   Nid of book in source database to lookup.
   */
  protected function lookupMigratedBook($source_book_nid) {
    $dest_book_nid = parent::handleSourceMigration('IslandNarrativesBookPage`', $source_book_nid);
    return $dest_book_nid;
  }

}
