#include<studio.h>
using namespace std;

struct TNode
{
    int data;
    TNode* left;
    TNode* right;
};
typedef TNode* Tree;

TNode* GetNewTNode (int data)
{
    TNode* p= new TNode;
    p->data=data;
    p->left=p->right=NULL;
    return p;

}

void CreateTree( Tree & t)
{
    t=NULL;
}

TNode* Insert(Tree &t, int data)
{ if (t==NULL)
  {
      t=GetNewTNode(data);
  }
  else if ( data <= t->data)
    {t->left=Insert(t->left,data);}
  else
    t->right=Insert(t->right,data);
    return t;
}

bool SearchTNode(Tree & t, int data)
{
    if (t==NULL)
        return false;
    else if (t->data==data)
        return true;
    else if (data<=t->data)
        return SearchTNode(t->left,data);
    else return SearchTNode(t->right,data);
}

void OutputNLR( Tree t)
{
    if (t!=NULL)
    {
        cout<<t->data<<" ";
        OutputNLR(t->left);
        OutputNLR(t->right);
    }
}

void OutputLRN( Tree t)
{
    if (t!=NULL)
    {
        OutputLRN(t->left);
        OutputLRN(t->right);
        cout<<t->data<<" ";

    }
}

void OutputLNR( Tree t)
{
    if (t!=NULL)
    {
        OutputLNR(t->left);
        cout<<t->data<<" ";
        OutputLNR(t->right);

    }
}

int ChieuCao( Tree root ){
	if( !root ) return -1;
	else return max( ChieuCao( root->left ) , ChieuCao( root->right ) ) + 1;
}

void XuatTheoTangK(Tree c, int k)
{
    if (c!=NULL)
    {
        k--;
        if (c->left != NULL)
            XuatTheoTangK(c->left,k);
        if (k==0)
            cout<<c->data<<" ";
        if (c->right != NULL)
            XuatTheoTangK(c->right,k);
    }
}


int maxDepth( Tree root ){
	if( !root ) return -1;
	else return max( maxDepth( root->left ) , maxDepth( root->right ) ) + 1;
}

int main()
{
    Tree t;
    TNode* p;
    int x,n,s;
    int luachon;
    cout<<"1.Tao mot node co key bang x"<<endl;
    cout<<"2.Them mot node vao cay nhi phan tim kiem"<<endl;
    cout<<"3.Them n node vao cay nhi phan tim kiem"<<endl;
    cout<<"4.Duyet node theo thu tu LRN,NLR,LNR"<<endl;
    cout<<"5.Tim mot node co key bang x"<<endl;
    cout<<"6.Thoat"<<endl;
    do {
        cout <<" Nhap lua chon:"<<endl;
        cin>>luachon;
        switch(luachon)
        {
        case 1 :
            {
                 CreateTree(t);
                 cout<<" Nhap gia tri cua node x:"<<endl;
                 cin>>x;
                 t=GetNewTNode(x);
                 break;
            }
        case 2 :
            {
                 CreateTree(t);
                 cout<<" Nhap gia tri cua 1 node x can them:"<<endl;
                 cin>>x;
                 Insert(t,x);
                 break;

            }
        case 3 :
            {
                CreateTree(t);
                cout<<" Ban muon them vao bao nhieu node ?"<<endl;
                cin>>n;
                for(int i=1;i<=n;i++)
                {
                cout<<"Nhap gia tri node thu "<<i<<":"<<endl;
                cin>>x;
                Insert(t,x);
                }
                break;
            }
        case 4 :
            {
                cout<<" Duyet node theo thu tu LNR:"<<endl;
                OutputLNR(t);
                cout<<endl<<" Duyet node theo thu tu NLR:"<<endl;
                OutputNLR(t);
                cout<<endl<<" Duyet node theo thu tu LRN:"<<endl;
                OutputLRN(t);
                break;
            }
        case 5 :
            {
                cout<<" Nhap gia tri cua node x can tim kiem:"<<endl;
                cin>>s;
                if (SearchTNode(t,s)==true)
                {
                cout<<" Da tim thay node x "<<endl;
                }
                else {cout<<" Khong tim thay node x"<<endl;}
                break;
            }
        case 7:
                int h=ChieuCao(t);
                cout<<ChieuCao(t)<<endl;
                for (int i=0; i<=h-1; i++)
    {
        XuatTheoTangK(t,i+1);
        cout<<endl;
    }
                break;

        }
    }while(luachon!=6);

    return 1;


}
