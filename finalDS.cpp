#include <iostream>
using namespace std;

class Node 
{
    public :
    string titleOfSong;
    Node*next;
};

class musicPlayListManger 
{
    public:
    Node*head ;
    musicPlayListManger()
    {
        head = NULL;
    };
    //___________________isEmpty______________________
    bool isEmpty(){
        return head == NULL;
    }
    //___________________addSong______________________
    void addSongFromHead(string title)
    {   
        Node* newNode = new Node();
        newNode->titleOfSong = title;
        if(isEmpty())
        {
            newNode->next=NULL;
            head = newNode;
        }
        else
        {
            newNode->next=head;
            head = newNode;
        };
    };
    
    void addSong (string title)
    {
        Node* newNode = new Node();
        newNode->titleOfSong = title;
        if(isEmpty())
        {
            newNode->next=NULL;
            head = newNode;
        }
        else if ( head->next == NULL )
        {
            head->next = newNode;
            newNode->next = NULL;
        }
        else
        {
            Node* temp = head;
            while ( temp->next != NULL )
            {
                temp = temp->next;
            }
            Node* newNode = new Node();
            newNode->titleOfSong = title;
            temp->next = newNode;
        }
    };

    void addSongBefore(string searchValue , string newValue) //the newNode will add before data 
    {   
        Node* newNode = new Node();
        newNode->titleOfSong = newValue;

        if (isEmpty())
        {
            newNode->next = NULL ;
            head = newNode ;
        }

        if ( head->titleOfSong == searchValue)
        {
            newNode->next = head;   
            head->next = NULL;
            head = newNode;
        }

        Node* temp = head;
        if (isGetSong(searchValue)) 
        {
            while ( temp != NULL && temp->next->titleOfSong != searchValue )
            {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
        else 
        {
            cout << searchValue << " is not found " << "\n" ;
            delete newNode ;
        };
    } 
    // ___________________________________display______________________________________________
    void display()
    {

        cout<<"\nCurrent List :\n";
        Node* temp = head ;
        int count = 0;

        while (temp!=NULL)
        {   

            cout << count+1 << "-" <<temp->titleOfSong << "\n" ;
            temp = temp->next;
            count++;
        }

        
        
    }

    void display(Node* newHead){
        cout<<"\nCurrent List :\n";
        int count = 0;
        Node* temp = newHead;
        
            while(temp != NULL){
            cout<<count<<"-"<<temp->titleOfSong<<"\n";
            temp = temp->next;
            count++;
            }	
        cout<<"\n";
    }
// ___________________________________________________find element_________________________________
    bool isGetSong(string key)  
    {
        bool found = false;
        Node* temp = head;
        while (temp != NULL)
        {
            if (temp->titleOfSong == key)
            {
                found = true ;
                break;
            }
            temp = temp->next;
            
        };
        return found;
    };

    int GetSongPlace(const string& key) {
    int index = 0;
    Node* temp = head;
    while (temp != NULL) {
        if (temp->titleOfSong == key) {
            return index;  // Song found, return the index
        }
        temp = temp->next;
        index++;
    }
    return -1;  // Song not found, return -1
}
//______________________________________________update____________________________
    void updatePlayList( string oldValue , string newValue )
    {   
        // cout << " the old Value " + oldValue << "\n" ;
        // cout << " the new Value " + newValue << "\n" ;
        Node* temp = head;
        while( temp != NULL && temp->titleOfSong != oldValue )
        {
            temp = temp->next;
        }
        temp->titleOfSong = newValue;
    };
//_______________________________________________remove___________________________
    void removeSong (string value)
    {   
        string removedValue ;
        if(head == NULL)
        {
            cout << "The play list is empty \n" ;
        }
        if(head->next == NULL)
        {
            removedValue = head->titleOfSong;
            delete head;
            cout << "removed value is :" << removedValue <<"\n";
        }
        if ( head->titleOfSong == value )
        {
            Node* temp = head;
            removedValue = head->titleOfSong ;
            head = head->next;
            delete temp;
            cout << "removed value is : " << removedValue <<"\n";
        }
        else
        {
            Node* delPtr = head;
            Node* prev = NULL;
            while ( delPtr->titleOfSong != value )
            {
                prev = delPtr;
                delPtr = delPtr->next ;
            }
            prev->next = delPtr->next;
            removedValue = delPtr->titleOfSong;
            delete delPtr;
            cout << "removed value is : " << removedValue <<"\n";
        }
    }
    void removeSong2(string value) {
    if (head == NULL) {
        cout << "The playlist is empty\n";
        return; 
    }

    Node* delPtr = head;
    Node* prev = NULL;

    
    if (head->titleOfSong == value) {
        head = head->next;
        cout << "Removed value is: " << delPtr->titleOfSong << "\n";
        delete delPtr;
        return;
    }

    while (delPtr != NULL && delPtr->titleOfSong != value) {
        prev = delPtr;
        delPtr = delPtr->next;
    }

    if (delPtr == NULL) {
        cout << "Value not found in the playlist\n";
        return;
    }

    prev->next = delPtr->next;
    cout << "Removed value is: " << delPtr->titleOfSong << "\n";
    delete delPtr;
}
    void removeFromHead()
    {   
        string removedValue ;
        Node* delPtr = head;
        removedValue = head->titleOfSong ;
        head = head->next;
        delete delPtr;
        
    };
    void removeFromTail()
    {
        string removedValue ;
        Node* delPtr = head;
        Node* temp = NULL;
        while (delPtr ->next != NULL)
        {   
            temp = delPtr;
            delPtr = delPtr->next;
        }
        removedValue = delPtr->titleOfSong;
        delete delPtr;
        temp->next = NULL;
    }
//___________________________________________
   
    void get_playlist_length(){
        int counter = 0;
        if (isEmpty())
        {
            cout<<"Your list is empty"<<endl;
        }
        else if(head->next == NULL){
            cout<<"list has one song"<<endl;
        }
        else {
            Node* temp = head;
            while (temp != NULL)
            {
                counter++;
                temp = temp->next;

            }
        cout<<"list has "<< counter <<" songs."<<endl;
        }
    }

    // clear_playlist(): Clear the entire playlist.
    void clear_playlist(){
        Node* curr = head;
        Node* next = NULL;
        while (curr != NULL)
        {
            next = curr->next;
            delete curr;
            curr = next;
        }
        head = NULL;
        cout<<"List is cleared"<<endl;
    }

    // reverse_playlist(): Reverse the order of songs in the playlist.
    void reverse_playlist(){
        Node* curr = head;
        Node* next = NULL;
        Node* prev = NULL;
        if (isEmpty() || head->next == NULL)
        {
            return;
        }
        else
        {
            while (curr != NULL)
            {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            head = prev;
        }
        
    }
    // copy_playlist(): copy the whole playlist.
    Node* copy_playlist(){
        if (isEmpty())
        {
            return NULL;
        }
        else
        {
            Node* newHead = new Node;
            newHead->titleOfSong = head->titleOfSong;
            newHead->next = NULL;
            Node* ptr1 = head->next;
            Node* ptr2 = newHead;
            while (ptr1 != NULL)
            {
                Node* newNode = new Node;
                newNode->titleOfSong = ptr1->titleOfSong;   
                newNode->next = NULL;
                ptr2->next = newNode;
                ptr2 = ptr2->next;
                ptr1 = ptr1->next;
            }
            return newHead;
        }
    }

    int countNodes() { // return the number of
    int count = 0;
    Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

    ~musicPlayListManger(){
        Node* curr = head;
        Node* next = NULL;
        while (curr != NULL)
        {
            next = curr->next;
            delete curr;
            curr = next;
        }
    }
    // shuffle_playlist(): Shuffle the songs in the playlist. // لو عايز تعملها وسهلة عليك لو مش عايز شيلها 
    //  move_song(current_position, new_position): Move a song from one position to another in the playlist. // ودي نفس الكلام برضو لو مش هتعملهم اعتبرهم متحطوش في ككومنت اصلا 
    // we will get the fullmark inshalla <3.
};

void showMainMenu(){ // shows the main menu options
    cout<<"\n";
    cout<<"1-Add a song\n";
    cout<<"2-Remove a song\n";
    cout<<"3-Display song list\n";
    cout<<"4-Revers list\n";
    cout<<"q-Exit\n";
    cout<<"\n";
}
void clearConsole(){
    system("cls");
}

int main() 
{
    

    bool run = true;
    musicPlayListManger list;
    string choice;


    while (run)
    {
        showMainMenu();
        cin>>choice;

        if(choice == "q"){ // exite the program if the user input is equal to "q"
        clearConsole();
            run = false;
        }
        else if(choice == "1" || choice == "add" || choice == "Add" || choice == "a"){
            clearConsole();
            string songName;
            cin>>songName;
            string method;
            cin>>method;
            
            if(method == "head"){
                list.addSongFromHead(songName);
            }else if(method == "tail"){
                list.addSong(songName);
            }else if(method == "before" || method == "bef" || method == "b"){
                string song;
                cin>>song;
                list.addSongBefore(song,songName);
            }
            

            // list.display(); ------------------
        }
       else if(choice == "2" || choice == "remove" || choice == "Remove" || choice == "r"){
         clearConsole();
        string songName;
        cin >> songName;
        
        if (songName == "all") {  // if the user input all clear all the list 
            if(list.isEmpty()){
                cout<<"\nlist is empty\n";
            }else{
                list.clear_playlist();
            }
        } else if (list.isGetSong(songName)) { // check if the song is in the list or not
            list.removeSong2(songName); // remove the song from the list
            if (!list.isEmpty()) {
                // list.display(); ---------------------
            } else {
                cout<<"\nlist is empty\n";
            }
        }else if(songName == "item" || songName == "i" || songName =="song" || songName == "s"){ // if user input i/item he chooses to remove from tail/head
            string pos;
            cin>>pos;
            if(pos == "head"){ // user removes from head
                list.removeFromHead();
            }else if(pos == "tail"){ // user removes from tail
                list.removeFromTail();
            }
        }
        else {
            cout << "\nError: Song not found\n";
        }
        }
       else if(choice == "3" || choice == "display" || choice == "Display" || choice == "d"){ // if user input equal to 3 / display ....
        
        if (list.isEmpty()) {
                cout << "List is empty";
        } else {
            clearConsole();
            list.display(); // show list items
            // cout<<"\n"<<"list has "<<list.get_playlist_length()<<" songs"<<"\n";
        
            
            list.get_playlist_length();
        }
        } 
       else if(choice == "4" || choice == "revers" || choice == "Revers" || choice == "rev"){ // if user input equal to 3 / display ....
        
            list.reverse_playlist();
        }         
    }
    



}