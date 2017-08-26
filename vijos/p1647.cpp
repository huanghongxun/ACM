#include <cstdio>
#include <cstring>

template <typename T>
class SizeBalancedTree
{
    private:

        struct SizeBalancedNode
        {
            T element;
            SizeBalancedNode * left;
            SizeBalancedNode * right;
            int node_size;

            SizeBalancedNode(const T & _element, 
                    SizeBalancedNode * lt, SizeBalancedNode * rt, int sz = 1)
                : element(_element), left(lt), right(rt), node_size(sz) {}
        };


    public:

        SizeBalancedTree()
        {
            root = NULL;
            tree_size = 0;
        }
        SizeBalancedTree(SizeBalancedTree & rhs)
        {
            this->root = clone(rhs.root);
            this->tree_size = rhs.size();
        }

        const SizeBalancedTree & operator = (const SizeBalancedTree & rhs)
        {
            if (this != &rhs)
            {
                this->clear();
                this->root = clone(rhs.root);
                this->tree_size = rhs.tree_size;
            }
            return (*this);
        }

        int size() const
        {
            return tree_size;
        }
        bool empty() const
        {
            return size() == 0;
        }
        bool contains(const T & x) const
        {
            return contains(x, root);
        }
        const T & findMin() const
        {
            if (empty())
            {
                throw 0; //UnderflowException();
            }
            return findMin(root)->element;
        }
        const T & findMax() const
        {
            if (empty())
            {
                throw 0; //UnderflowException();
            }
            return findMax(root)->element;
        }
        int rank(const T & x) const
        {
            if (!contains(x))
            {
                return -1;
            }
            return rank(x, root);
        }
        const T & select(int _rank) const
        {
            if (_rank < 0)
            {
                throw 0;//UnderflowException();
            }
            if (_rank >= size())
            {
                throw 1;//OverflowException();
            }
            return select(_rank, root)->element;
        }
        void insert(const T & x)
        {
            if (contains(x))
            {
                return ;
            }
            ++tree_size;
            insert(x, root);
            return ;
        }
        void remove(const T & x)
        {
            if (!contains(x))
            {
                return ;
            }
            --tree_size;
            remove(x, root);
            return ;
        }


    private:

        SizeBalancedNode * root;
        int tree_size;

        int getNodeSize(SizeBalancedNode * t) const
        {
            if (NULL == t)
            {
                return 0;
            }
            return t->node_size;
        }
        bool contains(const T & x, SizeBalancedNode * t) const
        {
            while (t != NULL)
            {
                if (x < t->element)
                {
                    t = t->left;
                }
                else if (t->element < x)
                {
                    t = t->right;
                }
                else
                {
                    return true;
                }
            }
            return false;
        }
        SizeBalancedNode * clone(SizeBalancedNode * t) const
        {
            if (NULL == t)
            {
                return NULL;
            }
            return new SizeBalancedNode(t->element, 
                clone(t->left), clone(t->right));
        }
        SizeBalancedNode * findMin(SizeBalancedNode * t) const
        {
            if (t != NULL)
            {
                while (t->left != NULL)
                {
                    t = t->left;
                }
            }
            return t;
        }
        SizeBalancedNode * findMax(SizeBalancedNode * t) const
        {
            if (t != NULL)
            {
                while (t->right != NULL)
                {
                    t = t->right;
                }
            }
            return t;
        }
        int rank(const T & x, SizeBalancedNode * t) const
        {
            int _rank = 0;
            while (t != NULL)
            {
                if (x < t->element)
                {
                    t = t->left;
                }
                else if (t->element < x)
                {
                    _rank += getNodeSize(t->left) + 1;
                    t = t->right;
                }
                else
                {
                    _rank += getNodeSize(t->left);
                    break ;
                }
            }
            return _rank;
        }
        SizeBalancedNode * select(int _rank, SizeBalancedNode * t) const
        {
            while (t != NULL)
            {
                if (_rank < getNodeSize(t->left))
                {
                    t = t->left;
                }
                else if (getNodeSize(t->left) < _rank)
                {
                    _rank -= getNodeSize(t->left) + 1;
                    t = t->right;
                }
                else
                {
                    break ;
                }
            }
            return t;
        }

        void rotateWithLeft(SizeBalancedNode * & k2)
        {
            SizeBalancedNode * k1 = k2->left;
            k2->left = k1->right;
            k1->right = k2;
            k1->node_size = getNodeSize(k2);
            k2->node_size = getNodeSize(k2->left) + getNodeSize(k2->right) + 1;
            k2 = k1;
            return ;
        }
        void rotateWithRight(SizeBalancedNode * & k2)
        {
            SizeBalancedNode * k1 = k2->right;
            k2->right = k1->left;
            k1->left = k2;
            k1->node_size = getNodeSize(k2);
            k2->node_size = getNodeSize(k2->left) + getNodeSize(k2->right) + 1;
            k2 = k1;
            return ;
        }
        void doubleWithLeft(SizeBalancedNode * & t)
        {
            rotateWithRight(t->left);
            rotateWithLeft(t);
            return ;
        }
        void doubleWithRight(SizeBalancedNode * & t)
        {
            rotateWithLeft(t->right);
            rotateWithRight(t);
            return ;
        }
        void maintain(SizeBalancedNode * & t)   //Need to optimize...
        {
            if (t->left != NULL)
            {
                if (getNodeSize(t->right) < getNodeSize(t->left->left))
                {
                    rotateWithLeft(t);
                }
                else if (getNodeSize(t->right) < getNodeSize(t->left->right))
                {
                    doubleWithLeft(t);
                }
            }
            if (t->right != NULL)
            {
                if (getNodeSize(t->left) < getNodeSize(t->right->right))
                {
                    rotateWithRight(t);
                }
                else if (getNodeSize(t->left) < getNodeSize(t->right->left))
                {
                    doubleWithRight(t);
                }
            }
            if (t->left != NULL)
            {
                maintain(t->left);
            }
            if (t->right != NULL)
            {
                maintain(t->right);
            }
            return ;
        }
        void simpleInsert(const T & x, SizeBalancedNode * & t)
        {
            if (NULL == t)
            {
                t = new SizeBalancedNode(x, NULL, NULL);
                return ;
            }
            ++t->node_size;
            if (x < t->element)
            {
                simpleInsert(x, t->left);
            }
            else if (t->element < x)
            {
                simpleInsert(x, t->right);
            }
            return ;
        }
        void insert(const T & x, SizeBalancedNode * & t)
        {
            if (NULL == t)
            {
                t = new SizeBalancedNode(x, NULL, NULL);
                return ;
            }
            ++t->node_size;
            if (x < t->element)
            {
                simpleInsert(x, t->left);
            }
            else if (t->element < x)
            {
                simpleInsert(x, t->right);
            }
            else
            {
                return ;
            }
            maintain(t);
            return ;
        }
        void remove(const T & x, SizeBalancedNode * & t)
        {
            if (NULL == t)
            {
                return ;
            }
            --t->node_size;
            if (x < t->element)
            {
                remove(x, t->left);
            }
            else if (t->element < x)
            {
                remove(x, t->right);
            }
            else
            {
                if (t->left != NULL && t->right != NULL)
                {
                    if (getNodeSize(t->left) < getNodeSize(t->right))
                    {
                        t->element = findMin(t->right)->element;
                        remove(t->element, t->right);
                    }
                    else
                    {
                        t->element = findMax(t->left)->element;
                        remove(t->element, t->left);
                    }
                }
                else
                {
                    SizeBalancedNode * oldNode = t;
                    t = ((t->left != NULL) ? t->left : t->right);
                    delete oldNode;
                    oldNode = NULL;
                }
            }
            return ;
        }

};

bool f[100005];

int main() {

    memset(f, 1, sizeof(f));

    int n, t, a, b;
    scanf("%d", &n);
    SizeBalancedTree<int> sbt;
    while(1) {
        scanf("%d%d", &t, &a);
        switch(t) {
        case 1:
            sbt.insert(a);
            break;
        case 2:
            f[a] = 0;
            break;
        case 3:
            if(!f[a])
                printf("Mei you. Zhe ge ke yi you. Zhe ge zhen mei you!\n");
            else {
                a = sbt.select(a);
                if(a > n)
                    printf("Dui bu qi,Mei you.\n");
                else {
                    printf("You. %d Yuan.\n", a);
                }
            }
            break;
        case 0:
            return 0;
        }
    }

    return 0;
}