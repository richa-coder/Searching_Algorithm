# Searching_Algorithm
If  some items in the list are searched for more frequently than others,this algorithm is a good alternative to naive linear search on linked list and arrays. By bubbling a found item towards the front of the list, further searches for that item can be performed quickly.
bool jw_search ( node*& list, int key, int*& rec ) // linear search on linked list
{
  
  bool find = false;
  node *j;

  for ( j = list; j != 0; j = j->next ) {
    if ( key == j->key )
      break;
  }
  if ( j != 0 ) {
    find = true;
    rec = &j->rec;
  }

  return find;
}

  Solution:use a list that is larger in size than the number of items by one.
 A list with 5 items would be allocated a size of 6 for use by the algorithm.
 There will be a speed improvement which  takes advantage of the fact that 80% of all operations are performed on 20% of the items in a data set.
 If those items are nearer to the front of the list then search will be sped up considerably. 
with a linked list the splicing operation required to restructure the list and send the item to the front is quick and trivial.On a linked data structure, moving an item to a new position over large distances has a constant time complexity, O(1), whereas for contiguous memory such as an array, the time complexity is O(N) where N is the range of items being shifted.
