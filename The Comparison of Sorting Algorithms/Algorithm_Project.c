/*  UFUK GURBUZ. 150113058  */

#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#include <windows.h>

struct eleman{
	int icerik;
	struct eleman *ileri;		// struct eleman
};

typedef struct eleman Eleman;
typedef Eleman * ElemanPtr;

struct liste{
	ElemanPtr bas;
	ElemanPtr son;			// struct liste
};

typedef struct liste Liste;
typedef Liste * ListePtr;

ElemanPtr elemanOlustur(int icerik){
	ElemanPtr eleman;
	eleman = malloc(sizeof(Eleman));
	
	eleman->icerik = icerik;		// elemanOlustur method
	eleman->ileri = NULL;
	
	return eleman;
}

ListePtr listeOlustur(){
	ListePtr liste;
	liste = malloc(sizeof(Liste));
										// listeOlustur method
	liste->bas = NULL;
	liste->son = NULL;
	
	return liste;
}


struct treeEleman{
	struct treeEleman *sol;
	int icerik;							// struct tree eleman
	struct treeEleman *sag;
};

typedef struct treeEleman TreeEleman;
typedef TreeEleman * TreeElemanPtr;

void basinaEkle(ListePtr liste, ElemanPtr eleman);
void sonunaEkle(ListePtr liste, ElemanPtr eleman);


int elemanSayisi(ListePtr liste);

void yazdir(ElemanPtr liste);


ElemanPtr insertSort(ElemanPtr node);


void mergeSort(ElemanPtr *headRef);
ElemanPtr SortedMerge(ElemanPtr a, ElemanPtr b);
void FrontBackSplit(ElemanPtr source, ElemanPtr *frontRef, ElemanPtr *backRef);


ElemanPtr getTail(ElemanPtr cur);
ElemanPtr partition(ElemanPtr head, ElemanPtr end, ElemanPtr *newHead, ElemanPtr *newEnd);
ElemanPtr quickSortRecur(ElemanPtr head, ElemanPtr end);
void quickSort(ElemanPtr *headRef);


TreeElemanPtr newNode(int item);
void inOrderPrint(TreeElemanPtr root);
TreeElemanPtr insert(TreeElemanPtr node, int icerik);
TreeElemanPtr treeSort(ElemanPtr *bas);

void copyList ( ElemanPtr q, ElemanPtr*s );
ElemanPtr listeyeEkle(char *path);

void cmpAlgorithms(char *path);

static unsigned int insertCmp = 0;
static unsigned int mergeCmp = 0;
static unsigned int quickCmp = 0;
static unsigned int treeCmp = 0;

void sifirla();

int main(){
	
	printf("\n\t\t\t<<< 2'SER - 1000 SAYI - DUZ >>>\n\n");
	cmpAlgorithms("inputFiles\\2ser_1000Sayi_Duz.txt");			// --> 1
	sifirla();
	
	printf("\n\t\t\t<<< 2'SER - 1000 SAYI - TERS >>>\n\n");
	cmpAlgorithms("inputFiles\\2ser_1000Sayi_Ters.txt");		// --> 2
	sifirla();
	
	printf("\n\t\t\t<<< 3'ER - 5000 SAYI - DUZ >>>\n\n");
	cmpAlgorithms("inputFiles\\3er_5000Sayi_Duz.txt");			// --> 3
	sifirla();
	
	printf("\n\t\t\t<<< 3'ER - 5000 SAYI - TERS >>>\n\n");
	cmpAlgorithms("inputFiles\\3er_5000Sayi_Ters.txt");			// --> 4
	sifirla();
	
	printf("\n\t\t\t<<< 5'ER - 10000 SAYI - DUZ >>>\n\n");
	cmpAlgorithms("inputFiles\\5er_10000Sayi_Duz.txt");			// --> 5
	sifirla();
	
	printf("\n\t\t\t<<< 5'ER - 10000 SAYI - TERS >>>\n\n");
	cmpAlgorithms("inputFiles\\5er_10000Sayi_Ters.txt");		// --> 6
	sifirla();
																								// All propabilities ( Best case, Worst case, Average case )
	printf("\n\t\t\t<<< 25'ER - 30000 SAYI - DUZ >>>\n\n");
	cmpAlgorithms("inputFiles\\25er_30000Sayi_Duz.txt");		// --> 7
	sifirla();
	
	printf("\n\t\t\t<<< 25'ER - 30000 SAYI - TERS >>>\n\n");
	cmpAlgorithms("inputFiles\\25er_30000Sayi_Ters.txt");		// --> 8
	sifirla();
	
	printf("\n\t\t\t<<< 50'SER - 50000 SAYI - DUZ >>>\n\n");
	cmpAlgorithms("inputFiles\\50ser_50000Sayi_Duz.txt");		// --> 9
	sifirla();
	
	printf("\n\t\t\t<<< 50'SER - 50000 SAYI - TERS >>>\n\n");
	cmpAlgorithms("inputFiles\\50ser_50000Sayi_Ters.txt");		// --> 10
	sifirla();
	
	printf("\n\t\t\t<<< 100'ER - 100000 SAYI - DUZ >>>\n\n");
	cmpAlgorithms("inputFiles\\100er_100000Sayi_Duz.txt");		// --> 11
	sifirla();
	
	printf("\n\t\t\t<<< 100'ER - 100000 SAYI - TERS >>>\n\n");
	cmpAlgorithms("inputFiles\\100er_100000Sayi_Ters.txt");		// --> 12
	sifirla();
	
	printf("\n\t\t\t<<< RANDOM 1000 SAYI >>>\n\n");
	cmpAlgorithms("inputFiles\\random1000Sayi.txt");			// --> 13
	sifirla();
	
	printf("\n\t\t\t<<< RANDOM 5000 SAYI >>>\n\n");
	cmpAlgorithms("inputFiles\\random5000Sayi.txt");			// --> 14
	sifirla();
	
	printf("\n\t\t\t<<< RANDOM 10000 SAYI >>>\n\n");
	cmpAlgorithms("inputFiles\\random10000Sayi.txt");			// --> 15
	sifirla();
	
	printf("\n\t\t\t<<< RANDOM 30000 SAYI >>>\n\n");
	cmpAlgorithms("inputFiles\\random30000Sayi.txt");			// --> 16
	sifirla();
	
	printf("\n\t\t\t<<< RANDOM 100000 SAYI >>>\n\n");
	cmpAlgorithms("inputFiles\\random100000Sayi.txt");			// --> 17
	sifirla();
}

void sifirla(){
	insertCmp = 0;
	mergeCmp = 0;
	quickCmp = 0;
	treeCmp = 0;
}

void cmpAlgorithms(char *path){
	LARGE_INTEGER frequency;
    LARGE_INTEGER start;
    LARGE_INTEGER end;
    double interval;
	
	
	ElemanPtr liste_bas = listeyeEkle(path);	// Asil Linked List
	ElemanPtr tmp;	

	
	//----- 1 -----
	copyList(liste_bas, &tmp);		// Temp Linked List

    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&start);
    
	ElemanPtr inserted = insertSort(tmp);
	//yazdir(inserted);
	
	QueryPerformanceCounter(&end);
    interval = (double) (end.QuadPart - start.QuadPart) / frequency.QuadPart;
    printf("Insertion Sort Time: %11f\tComparison: %u\n", interval, insertCmp);
	
	
	//----- 2 -----
	copyList(liste_bas, &tmp);		// Temp Linked List
	
	QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&start);
    
	mergeSort(&tmp);
	//yazdir(tmp);
	
	QueryPerformanceCounter(&end);
    interval = (double) (end.QuadPart - start.QuadPart) / frequency.QuadPart;
    printf("Merge Sort Time: %15f\tComparison: %u\n", interval, mergeCmp);
	
	
	//----- 3 -----
	copyList(liste_bas, &tmp);		// Temp Linked List
	
	QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&start);
    
	quickSort(&tmp);
	//yazdir(tmp);
	
	QueryPerformanceCounter(&end);
    interval = (double) (end.QuadPart - start.QuadPart) / frequency.QuadPart;
    printf("Quick Sort Time: %15f\tComparison: %u\n", interval, quickCmp);
	

	//----- 4 -----
	copyList(liste_bas, &tmp);		// Temp Linked List
	
	QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&start);
    
	TreeElemanPtr root = treeSort(&tmp);
	//inOrderPrint(root);
	
	QueryPerformanceCounter(&end);
    interval = (double) (end.QuadPart - start.QuadPart) / frequency.QuadPart;
    printf("Tree Sort Time: %16f\tComparison: %u\n", interval, treeCmp);
	
		
	printf("\n\n");
}

ElemanPtr listeyeEkle(char *path){
	ListePtr liste = listeOlustur();
	FILE *filePtr = fopen(path,"r");
	int sayi;
	
	while(!feof(filePtr)){
		fscanf(filePtr, "%d", &sayi);
	 	ElemanPtr eleman = elemanOlustur(sayi);
		sonunaEkle(liste, eleman);
	}
		
	ElemanPtr liste_bas = liste->bas;
	
	return liste_bas;
}

void copyList ( ElemanPtr q, ElemanPtr*s ){
    if ( q != NULL ){
        *s = malloc ( sizeof ( Eleman ) ) ;

        ( *s ) -> icerik = q -> icerik ;
        ( *s ) -> ileri = NULL ;

        copyList ( q -> ileri, &( ( *s ) -> ileri ) ) ;
    }
}

/////////////////////////////////////////////////  BASLANGIC INSERTION /////////////////////////////////////////////////////

ElemanPtr insertSort(ElemanPtr node){

   ElemanPtr sortedList = NULL;
   while(node != NULL){
    ElemanPtr current = node;
    node = node->ileri;
    ElemanPtr x;
    ElemanPtr previous = NULL;
    for(x = sortedList; x != NULL; x = x->ileri){
    	insertCmp++;
        if(current->icerik > x->icerik){					// Insertion Sorting Algorithm
                break;
         }
         previous = x;
    }
    if(previous == NULL){               
          current->ileri = sortedList;
          sortedList = current;
    }
    else{               
       current->ileri = previous->ileri;
       previous->ileri = current;
    }
  }
  return sortedList;
}

/////////////////////////////////////////////////  BITIS INSERTION ////////////////////////////////////////////////////////////



/////////////////////////////////////////////////  BASLANGIC MERGE ////////////////////////////////////////////////////////////
void mergeSort(ElemanPtr *headRef){
	
	ElemanPtr head = *headRef;
	ElemanPtr a;
	ElemanPtr b;

	/* Base case -- length 0 or 1 */
	if ((head == NULL) || (head->ileri == NULL))
		return;

	/* Split head into 'a' and 'b' sublists */
	FrontBackSplit(head, &a, &b); 
	
	/* Recursively sort the sublists */
	mergeSort(&a);
	mergeSort(&b);
	
	/* answer = merge the two sorted lists together */
	*headRef = SortedMerge(a, b);
}


ElemanPtr SortedMerge(ElemanPtr a, ElemanPtr b){
	
	ElemanPtr result = NULL;

	/* Base cases */
	if (a == NULL)											// Merge Sorting Algorithm
		return(b);
	
	else if (b==NULL)
		return(a);
	
	mergeCmp++;
	
	/* Pick either a or b, and recur */
	if (a->icerik <= b->icerik){
		result = a;
		result->ileri = SortedMerge(a->ileri, b);
	}
	
	else{
		result = b;
		result->ileri = SortedMerge(a, b->ileri);
	}
	
	return(result);
}


void FrontBackSplit(ElemanPtr source, ElemanPtr *frontRef, ElemanPtr *backRef){
	
	ElemanPtr fast;
	ElemanPtr slow;
	
	if (source==NULL || source->ileri==NULL){
		/* length < 2 cases */
		*frontRef = source;
		*backRef = NULL;
	}
	else{
		slow = source;
		fast = source->ileri;
	
		/* Advance 'fast' two nodes, and advance 'slow' one node */
		while (fast != NULL){
			fast = fast->ileri;
			if (fast != NULL){
				slow = slow->ileri;
				fast = fast->ileri;
			}
		}
	
		/* 'slow' is before the midpoint in the list, so split it in two at that point. */
		
		*frontRef = source;
		*backRef = slow->ileri;
		slow->ileri = NULL;
	}
}

/////////////////////////////////////////////////  BITIS MERGE ////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////  BASLANGIC QUÝCK ////////////////////////////////////////////////////////////

ElemanPtr getTail(ElemanPtr cur){
	while (cur != NULL && cur->ileri != NULL)
		cur = cur->ileri;
	return cur;
}

// Partitions the list taking the last element as the pivot
ElemanPtr partition(ElemanPtr head, ElemanPtr end, ElemanPtr *newHead, ElemanPtr *newEnd){
	
	ElemanPtr pivot = end;
	ElemanPtr prev = NULL, cur = head, tail = pivot;

	// During partition, both the head and end of the list might change which is updated in the newHead and newEnd variables
	while (cur != pivot) {
		
		quickCmp++;
		
		if (cur->icerik < pivot->icerik){
			// First node that has a value less than the pivot - becomes the new head
			if ((*newHead) == NULL)
				(*newHead) = cur;

			prev = cur; 
			cur = cur->ileri;
		}
		else{  // If cur node is greater than pivot
			// Move cur node to next of tail, and change tail
			if (prev)
				prev->ileri = cur->ileri;								// Quick Sorting Algorithm
			
			ElemanPtr tmp = cur->ileri;
			cur->ileri = NULL;
			tail->ileri = cur;
			tail = cur;
			cur = tmp;
		}
	}

	// If the pivot data is the smallest element in the current list,
	// pivot becomes the head
	if ((*newHead) == NULL)
		(*newHead) = pivot;

	// Update newEnd to the current last node
	(*newEnd) = tail;

	// Return the pivot node
	return pivot;
}


//here the sorting happens exclusive of the end node
ElemanPtr quickSortRecur(ElemanPtr head, ElemanPtr end){
	// base condition
	if (!head || head == end)
		return head;

	ElemanPtr newHead = NULL, newEnd = NULL;

	// Partition the list, newHead and newEnd will be updated by the partition function
	ElemanPtr pivot = partition(head, end, &newHead, &newEnd);

	// If pivot is the smallest element - no need to recur for the left part.
	if (newHead != pivot){
		// Set the node before the pivot node as NULL
		ElemanPtr tmp = newHead;
		
		while (tmp->ileri != pivot)
			tmp = tmp->ileri;
		
		tmp->ileri = NULL;

		// Recur for the list before pivot
		newHead = quickSortRecur(newHead, tmp);

		// Change next of last node of the left half to pivot
		tmp = getTail(newHead);
		tmp->ileri = pivot;
	}

	// Recur for the list after the pivot element
	pivot->ileri = quickSortRecur(pivot->ileri, newEnd);

	return newHead;
}

// The main function for quick sort. This is a wrapper over recursive function quickSortRecur()

void quickSort(ElemanPtr *headRef){
	(*headRef) = quickSortRecur(*headRef, getTail(*headRef));
	return;
}


/////////////////////////////////////////////////  BITIS QUÝCK ////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////  BASLANGIC TREE /////////////////////////////////////////////////////////////

TreeElemanPtr newNode(int item){
	TreeElemanPtr temp = (TreeElemanPtr)malloc(sizeof(TreeEleman));
	temp->icerik = item;
	temp->sol = temp->sag = NULL;
	return temp;
}

// A utility function to do inorder traversal of BST
void inOrderPrint(TreeElemanPtr root){
	
	if (root != NULL){
		inOrderPrint(root->sol);
		printf("Veri: %d \n", root->icerik);
		inOrderPrint(root->sag);
	}
	
}

/* A utility function to insert a new node with given key in BST */
TreeElemanPtr insert(TreeElemanPtr node, int icerik){
	/* If the tree is empty, return a new node */
	if (node == NULL)													// Tree Sorting Algorithm
		return newNode(icerik);
	
	treeCmp++;
	
	/* Otherwise, recur down the tree */
	if (icerik < node->icerik)
		node->sol = insert(node->sol, icerik);
	else if (icerik > node->icerik)
		node->sag = insert(node->sag, icerik); 

	/* return the (unchanged) node pointer */
	return node;
}

TreeElemanPtr treeSort(ElemanPtr *bas){
	ElemanPtr tmp = *bas;
	
	TreeElemanPtr root = NULL;
	
	root = insert(root, tmp->icerik);
	tmp = tmp->ileri;
	
	while(tmp != NULL){
		insert(root, tmp->icerik);
		tmp = tmp->ileri;
	}
	return root;
}


/////////////////////////////////////////////////  BITIS TREE /////////////////////////////////////////////////////////////////


void basinaEkle(ListePtr liste, ElemanPtr eleman){			// Basina ekler.
	if(liste->son == NULL)
		liste->son = eleman;
	else
		eleman->ileri = liste->bas;
	liste->bas = eleman;
}

void sonunaEkle(ListePtr liste, ElemanPtr eleman){			// Sonuna ekler.
	if(liste->bas == NULL)
		liste->bas = eleman;
	else
		liste->son->ileri = eleman;
	liste->son = eleman;
}

void yazdir(ElemanPtr node){
	while (node != NULL)
	{
		printf("Veri: %d \n", node->icerik);		// Listeyi yazdirir.
		node = node->ileri;
	}
	printf("\n");
}

