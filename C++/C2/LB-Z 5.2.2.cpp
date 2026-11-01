//AVL-Дервео с различными методами (сбалансированное двоичное дерево поиска) - Шаблонный класс.
//Вариант: 16.
//=============================================================================================
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

template<typename T>
class AVLTree {
    struct Node {
        T vrem;
        Node* left;
        Node* right;
        int height;
        
        Node(T val) : vrem(val), left(nullptr), right(nullptr), height(1) {}
    };
    
    Node* root;

public:
    AVLTree() : root(nullptr) {}
    
    AVLTree(const AVLTree& other) : root(nullptr) {
        copyTree(other.root);
    }
    
    AVLTree& operator=(const AVLTree& other) {
        if (this != &other) {
            clear();
            copyTree(other.root);
        }
        return *this;
    }
    
    ~AVLTree() {
        clear();
    }

    bool poisk(T vrem) {
        return poiskR(root, vrem);
    }

    void insert(T vrem) {
        root = insertR(root, vrem);
    }
    
    void remove(T vrem) {
        root = removeR(root, vrem);
    }
    
    string toString() {
        string result = "";
        toStringR(root, result);
        return result;
    }
    
    // Вывод в поток
    friend ostream& operator<<(ostream& os, const AVLTree& tree) {
        tree.writeToStreamR(tree.root, os);
        return os;
    }
    
    // Чтение из потока
    friend istream& operator>>(istream& is, AVLTree& tree) {
        tree.clear();
        T value;
        while (is >> value) {
            tree.insert(value);
        }
        is.clear();
        return is;
    }
    
    // Вертикальный вывод дерева
    void print() {
        cout << "AVL Дерево (вертикальный вывод):" << endl;
        cout << "====================" << endl;
        printVertical();
        cout << "====================" << endl;
    }
    
    // Горизантальный вывод
    void printCompact() {
        cout << "AVL Дерево (горизонтальный вывод):" << endl;
        cout << "====================" << endl;
        printVerticalCompact(root, 0);
        cout << "====================" << endl;
    }
    
    // Очистка дерева
    void clear() {
        clearR(root);
        root = nullptr;
    }
    
    // Проверка на пустоту
    bool empty() {
        return root == nullptr;
    }

private:
    // Копирование дерева
    void copyTree(Node* node) {
        if (node) {
            insert(node->vrem);
            copyTree(node->left);
            copyTree(node->right);
        }
    }
    
    // Получение высоты узла
    int getHeight(Node* node) {
        if (node == nullptr) return 0;
        return node->height;
    }
    
    // Получение баланса узла
    int getBalance(Node* node) {
        if (node == nullptr) return 0;
        return getHeight(node->left) - getHeight(node->right);
    }
    
    // Правый поповрот
    Node* rotateRight(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;
        
        x->right = y;
        y->left = T2;
        
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        
        return x;
    }
    
    // Левый поворот
    Node* rotateLeft(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;
        
        y->left = x;
        x->right = T2;
        
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        
        return y;
    }
    
    // Рекурсивный поиск
    bool poiskR(Node* node, T vrem) {
        if (node == nullptr) return false;
        
        if (vrem == node->vrem) {
            return true;
        }
        if (vrem < node->vrem) {
            return poiskR(node->left, vrem);
        } else {
            return poiskR(node->right, vrem);
        }
    }
    
    // Рекурсивная вставка
    Node* insertR(Node* node, T vrem) {
        if (node == nullptr) {
            return new Node(vrem);
        }
        
        if (vrem < node->vrem) {
            node->left = insertR(node->left, vrem);
        } else if (vrem > node->vrem) {
            node->right = insertR(node->right, vrem);
        } else {
            return node; 
        }
        
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        
        int balance = getBalance(node);
        
        if (balance > 1 && vrem < node->left->vrem) {
            return rotateRight(node);
        }
        
        if (balance < -1 && vrem > node->right->vrem) {
            return rotateLeft(node);
        }
        
        if (balance > 1 && vrem > node->left->vrem) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
        
        if (balance < -1 && vrem < node->right->vrem) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }
        return node;
    }
    
    // Поиск минимального узла
    Node* findMin(Node* node) {
        while (node && node->left) {
            node = node->left;
        }
        return node;
    }
    
    // Рекурсивное удаление
    Node* removeR(Node* node, T vrem) {
        if (!node) return nullptr;
        
        if (vrem < node->vrem) {
            node->left = removeR(node->left, vrem);
        } else if (vrem > node->vrem) {
            node->right = removeR(node->right, vrem);
        } else {
            if (!node->left || !node->right) {
                Node* temp = node->left ? node->left : node->right;
                
                if (!temp) {
                    temp = node;
                    node = nullptr;
                } else {
                    *node = *temp;
                }
                
                delete temp;
            } else {
                Node* temp = findMin(node->right);
                node->vrem = temp->vrem;
                node->right = removeR(node->right, temp->vrem);
            }
        }
        
        if (!node) return node;
        
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        
        int balance = getBalance(node);
        
        if (balance > 1 && getBalance(node->left) >= 0) {
            return rotateRight(node);
        }
        
        if (balance > 1 && getBalance(node->left) < 0) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
        
        if (balance < -1 && getBalance(node->right) <= 0) {
            return rotateLeft(node);
        }
        
        if (balance < -1 && getBalance(node->right) > 0) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }
        return node;
    }
    
    // Очистка дерева
    void clearR(Node* node) {
        if (node) {
            clearR(node->left);
            clearR(node->right);
            delete node;
        }
    }
    
    // Превращение в строку
    void toStringR(Node* node, string& result) const {
        if (node) {
            toStringR(node->left, result);
            if (!result.empty()) {
                result += " ";
            }
            stringstream ss;
            ss << node->vrem;
            result += ss.str();
            toStringR(node->right, result);
        }
    }
    
    // Запись в поток
    void writeToStreamR(Node* node, ostream& os) const {
        if (node) {
            writeToStreamR(node->left, os);
            os << node->vrem << " ";
            writeToStreamR(node->right, os);
        }
    }

    // Получение глубины дерева
    int getDepth(Node* node) const {
        if (node == nullptr) return 0;
        int leftDepth = getDepth(node->left);
        int rightDepth = getDepth(node->right);
        return 1 + (leftDepth > rightDepth ? leftDepth : rightDepth);
    }
    
    // Рекурсивный вывод уровня
    void printLevel(Node* node, int level, int spaces) const {
        if (node == nullptr) {
            // Вывод пустых мест для выравнивания
            for (int i = 0; i < spaces; i++) {
                cout << " ";
            }
            cout << "   ";
            return;
        }
        
        if (level == 1) {
            for (int i = 0; i < spaces; i++) {
                cout << " ";
            }
            cout << node->vrem << "(" << node->height << ")";
        } else if (level > 1) {
            printLevel(node->left, level - 1, spaces / 2);
            printLevel(node->right, level - 1, spaces / 2);
        }
    }
    
    // Вертикальный вывод дерева
    void printVertical() const {
        if (root == nullptr) {
            cout << "Дерево пустое" << endl;
            return;
        }
        
        int depth = getDepth(root);
        
        for (int level = 1; level <= depth; level++) {
            cout << "Уровень " << level << ": ";
            printLevel(root, level, 8 * (depth - level + 1));
            cout << endl;
        }
    }
    
    // Ещё один вертикальный вывод (альтернативный)
    void printVerticalCompact(Node* node, int space) const {
        if (node == nullptr) return;
        space += 10;
        printVerticalCompact(node->right, space);
        cout << endl;
        for (int i = 10; i < space; i++) {
            cout << " ";
        }
        cout << node->vrem << "(" << node->height << ")" << endl;
        printVerticalCompact(node->left, space);
    }
    
    // Вспомогательная функция для max
    int max(int a, int b) const {
        return (a > b) ? a : b;
    }
};

int main() {
    AVLTree<int> tree;
    
    // Добавление элементов в дерево
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);
    
    cout << "Содержимое дерева: " << tree << endl;
    
    cout << "\nПодробный вывод дерева:" << endl;
    tree.print();
    
    cout << "Есть ли 30 в дереве: " << (tree.poisk(30) ? "Да" : "Нет") << endl;
    cout << "Есть ли 55 в дереве: " << (tree.poisk(55) ? "Да" : "Нет") << endl;
    
    cout << "\nУдаляем элемент 30" << endl;
    tree.remove(30);
    cout << "Содержимое после удаления: " << tree << endl;
   
    cout << "\nПустое дерево: " << (tree.empty() ? "Да" : "Нет") << endl;

    // Тест чтения из потока
    AVLTree<int> tree2;
    stringstream ss("100 50 150 25 75 125 175");
    
    cout << "\nЧтение дерева из строки..." << endl;
    ss >> tree2;
    cout << "Новое дерево из строки: " << tree2 << endl;
    
    cout << "\nПодробный вывод нового дерева:" << endl;
    tree2.print();
    
    // Тест с другими типами данных
    AVLTree<string> tree3;
    tree3.insert("banana");
    tree3.insert("apple");
    tree3.insert("cherry");
    tree3.insert("date");
    
    cout << "\nДерево строк: " << tree3 << endl;
    
    return 0;
}
//Ужас...
