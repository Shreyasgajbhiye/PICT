void DLLNode::display(DLLNode *Head)
{
    DLLNode *temp;

    cout<<"\n\n\t Head->";
    temp = Head;
    while(temp != NULL)
    {
        cout<<"->|"<<temp->bit<<"|<-";
        temp = temp->next;
    }
}
