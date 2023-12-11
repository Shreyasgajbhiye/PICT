void display(){
        Node *ptr = this->front;
        while(ptr!=NULL){
            cout << "(" << ptr->pid << ", " << ptr->priority << ") -> ";
            ptr = ptr->next;
        }
    }