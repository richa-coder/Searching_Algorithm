struct node {   /*node Structure*/
  int rec;
  int key;
  node *next;

  node ( int r, int k, node *n )
    : rec ( r )
    , key ( k )
    , next ( n )
  {}
};

bool jw_search ( node*& list, int key, int*& rec ) /* Efficient Searching*/
{
  // Self-organizing (move to front) search
  node *iter = list;
  bool found = false;

  // Is it already at the front?
  if ( key == iter->key ) {
    rec = &iter->rec;
    found = true;
  }
  else {
    for ( ; iter->next != 0; iter = iter->next ) {
      if ( key == iter->next->key )
        break;
    }
    // Was the item found?
    if ( iter->next != 0 ) {
      // Remove the node and fix the list
      node *save = iter->next;
      iter->next = save->next;
      // Place the node at the front
      save->next = list;
      list = save;
      rec = &list->rec;
      found = true;
    }
  }

  return found;
} // algorithm Ends
// with a linked list the splicing operation required to restructure the list and send the item to the front is quick and trivial.or a linked data structure, moving an item to a new position over large distances has a constant time complexity, O(1), whereas for contiguous memory such as an array, the time complexity is O(N) where N is the range of items being shifted.