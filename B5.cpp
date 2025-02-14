#include<iostream>
#include<string.h>
using namespace std;

struct node
{
    string label;
    int ch_count;
    struct node* child[20];
};

node *root;

class Tree
{
public:
    Tree()
    {
        root = NULL;
    }

    void create()
    {
        root = new node;

        cout << "Enter the name of book: ";
        cin >> root->label;
        cout << "Enter the number of chapters: ";
        cin >> root->ch_count;

        for (int i = 0; i < root->ch_count; i++)
        {
            root->child[i] = new node;
            cout << "Enter the name of chapter " << i + 1 << ": "<<endl;
            cin >> root->child[i]->label;
            cout << "Enter the number of sections: "<<endl;
            cin >> root->child[i]->ch_count;

            for (int j = 0; j < root->child[i]->ch_count; j++)
            {
                root->child[i]->child[j] = new node;
                cout << "Enter the name of section " << j + 1 << ": "<<endl;
                cin >> root->child[i]->child[j]->label;
                cout << "Enter the number of sub-sections: "<<endl;
                cin >> root->child[i]->child[j]->ch_count;

                for (int k = 0; k < root->child[i]->child[j]->ch_count; k++)
                {
                    root->child[i]->child[j]->child[k] = new node;
                    cout << "Enter the name of sub-section " << k + 1 << ": "<<endl;
                    cin >> root->child[i]->child[j]->child[k]->label;
                }
            }
        }
    }

    void display(node *root, int level = 0)
    {
        if (root == NULL)
        {
            cout << "Please form the tree first!" << endl;
            return;
        }
    
        // Indentation for hierarchy
        string indent(level * 4, ' ');
    
        // Print the current node
        cout << indent <<  "  "<< root->label << endl;
    
        // Iterate through child nodes (Chapters -> Sections -> Sub-sections)
        for (int i = 0; i < root->ch_count; i++)
        {
            cout << indent << "  Chapter " << i + 1 << ": " << root->child[i]->label << endl;
    
            for (int j = 0; j < root->child[i]->ch_count; j++)
            {
                cout << indent << "    Section " << j + 1 << ": " << root->child[i]->child[j]->label << endl;
    
                for (int k = 0; k < root->child[i]->child[j]->ch_count; k++)
                {
                    cout << indent << "      Sub-section " << k + 1 << ": " << root->child[i]->child[j]->child[k]->label << endl;
                }
            }
        }
    }
};    

int main()
{
    Tree T;

    while (1)
    {
        cout << "-------MENU--------" << endl;
        cout << "1. Create" << endl;
        cout << "2. Display" << endl;
        cout << "3. Exit" << endl;

        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
            T.create();
            break;
        case 2:
            T.display(root);
            break;
        case 3:
            cout << "EXITING..." << endl;
            return 0; // Exit the program after displaying message
        default:
            cout << "Enter a valid choice!!" << endl;
            break;
        }
    }
    return 0;
}

