#preorder in BST 
preorder(root)
	print(root)
	if(root -> left != NULL)
		preorder(root->left);
	else if(root->right != NULL)
		preorder(root->right);
		
#Inorder in BST
inorder(root):
	if(root->left != NULL)
		inorder(root->left)
	print(root)
	if(root->right != NULL)
		inorder(root->right)

#List All directories in linux	
LIst_files:
	struct dirent* dentry = NULL;
	while((entry = readdir(dp)) != NULL)
	{	
		if(dentry -> d_type != DT_DIR)
		{
			print(dentry->d_name);
		}
		else
		{
			List_files(dentry->d_name);
		}
		
	}
	
    
#Search algorithm for BST
node* Search(root,node):
    if(root == NULL)
        return(NOT_FOUND)
    else if(node->value > root->value)
        search(root->right , node)
    else if(node->value < root->value)
        search(root->left,node)
    else if(node->value == root->value)
        return node

#calculate height of the tree

height_bst_nodelevel(root):
    if(root == NULL)
        
    
    
    
count hight(root):
    if(root == NULL)
        return 0;
    else
        left_height = height_bst_nodelevel(node->left)
        right_height = height_bst_nodelevel(node->right)
        
        if( right_height > left_height)
            return right_height + 1
        else 
            return left_height + 1
            
#let a be a array of N elements Assume that A is interpreted as a nearly complete binary tree. then write algorithm for 
#list1 = [5,15,7,9,25,31,75,40,65,100]

#1) compute index of left child of elemnt at index i 
compute_left_index(int i):
    return 2*i + 1

#2) Compute index of Right child of element at index i(algorithm should determine if left or right child exists for the index i)
    compute_right_child(int i):
        return 2*i + 2
        
#3)compute idex of parent element of elemnt at index i
    compute_parent_of_inndex(int i):
        return floor(i -1/2)
#4)Find the last element in a array A, having at least one child.  
    compute_last_element_with_one_child(int i):
        return floor(N/2) - 1
        
#inorderSuccessor
inoderpredessor(node):
   if(node->left != NULL):
        greatestofLeftSubtree()
   
   # but what if node->left == NULL
   #todo

