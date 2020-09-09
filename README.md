# Migrate Book Structure

There have been several requests on Drupal.org about
how migrating books does not preserve the structure
hierarchy of a book.

This module contains a Drupal 7 Drush task to examine a
previously-run migration's source and target databases and
will re-construct the source book structure in the target Drupal's
book and menu tables.

## Fixing Links in Body Text

This module also provides a Drush command to search through 
all imported pages' body text and update internal links to point
to the migrated node. The command will also look for external-style
links that should be internal node links. This will allow administrators
to change the URL paths of migrated content without breaking
these previously-hardcoded links.

# Requirements

This module works after a migration has been run. 

It was not made into a migrate plugin due partly to the 
difficulty of Drupal 7's migrate API, but also because migrate
plugins act on each node as it is imported, but to re-create 
a book's structure, one must traverse the book's structure
from top-to-bottom, and there is no guarantee that a node's
parents will all have been previously imported when a given
node is being processed. It is also possible to run after a
Drupal-to-Drupal migration is performed.

# Usage

1. Run a migration, for example, a [Drupal-to-Drupal](https://www.drupal.org/project/migrate_d2d) migration
of Book and Page content from a Drupal 6 site.
2. Backup the target site's database. These commands run 
    across many nodes so be sure to do a backup first.
3. Add the source database to the $databases array in settings.php.
4. Find the migration machine name. D2D generates a random 
    alpha-numeric machine name when you create a migration.
5. Run the Drush command to construct book hierarchy:

    drush mbspbh --dbconnection=[source database] --migration=[Migrate job machien name] --types=book,page
    
6. Run the command to process body text links:

    drush minpil --migration=[migration machine name] --types=book,page
    
    This command outputs all of the links that get updated or not.
    You should capture these to a text file or spreadsheet so you can
    do a content audit.

The --dry-run=TRUE option will print out the set of links that will get
changed without saving the changes.
