[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-c66648af7eb3fe8bc4f294546bfd86ef473780cde1dea487d3c4ff354943c9ae.svg)](https://classroom.github.com/online_ide?assignment_repo_id=9773858&assignment_repo_type=AssignmentRepo)
# Introduction to C++ templates

## Task
Create a linked list along with all specified functions that should be able to store any specified data type of data using C++ templates.
### Data types the linked list should support:
	Integer
	Character
	String (char *)

### Node Structure

    struct node {
        data
        next
    };

### Functions Needed

    // insert a new node with the specified data in the back of the list
    insert_back(data, linked_list_pointer);  

    // insert a new node with the specified data in the front of the list
    insert_front(data, linked_list_pointer); 

    // print the linked list data, data of each node should be on a new line
    print_list(linked_list_pointer);         

    // search the linked list for the first instance where data is found and return the pointer to that node
    search_list(data, linked_list_pointer);  

    // remove the last node of the linked list
    remove_back(linked_list_pointer);        

    // remove the first node of the linked list
    remove_front(linked_list_pointer);       
			
## Example `main`

    int main(int argc, char **argv)
    {
        node<int>* ll = NULL;
        
        insert_back<int>(1, ll);
        insert_back<int>(2, ll);
        insert_back<int>(3, ll);
        
        print_list<int>(ll);
        
        node<int>* sll = search_list<int>(4, ll);
        
        if (sll == NULL)
        {
            printf("Value not found\n");
        }
        else
        {
            printf("Value was found\n");
        }
        
        remove_back<int>(ll);
        remove_back<int>(ll);
        remove_back<int>(ll);
        
        return 0;
    }
