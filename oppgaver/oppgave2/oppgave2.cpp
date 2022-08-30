/**
 * @file oppgave2.cpp
 * @author dan
 * @brief
 * @version 0.1
 * @date 2022-08-27
 *
 * @copyright Copyright (c) 2022
 *
 * Selvlaget map til oppgave 2 av dan
 *
 */

#include <iostream> // cout
#include <string>   // string

using namespace std;

/**
 * Container-klasse Map, som er selvlaget
 * Konstruere en tom map
 *
 * - Antallet i map’en
 * - Skrive hele map’ens innhold
 * - Sette inn et nytt par med key og data
 * - Finne (om mulig) en key
 * - Hente ut en keys tilhørende data
 * - Endre en allerede eksisterende keys tilhørende data (duplikate keyer får jo ikke
 * - lov til å forekomme, derfor endres evt. en eksisterende keys tilhørende data)
 * - Slette helt paret med key og data

 *
 */
template <typename K, typename V> // https://www.learncpp.com/cpp-tutorial/function-templates-with-multiple-template-types/
class Map
{
private:
    // T *data;
    struct KeySet
    {
        K mKey;
        V mValue;
        KeySet *nextKeySet;
        KeySet(const K k, const V v)
        {
            mKey = k;
            mValue = v;
            nextKeySet = nullptr;
        } // Constructor.
    };

    KeySet *base;

    // KeySet *head;
    int mSize; // https://stackoverflow.com/questions/467815/class-method-and-variable-with-same-name-compile-error-in-c-not-in-java

public:
    Map()
    {
        mSize = 0;
    }

    Map(const K key, const V value)
    {
        // data = new T[1];
        base = new KeySet(key, value);
        // base->nextKeySet = head;
        // head = base;
        mSize = 1;
    }

    ~Map()
    {
        KeySet *keySetPointer;
        while (base)
        {
            keySetPointer = base->nextKeySet;
            delete base;
            base = keySetPointer;
        }
    }

    void put(const K key, const V value)
    {
        if (mSize == 0)
        {
            base = new KeySet(key, value);
            mSize++;
        }
        else
        {
            KeySet* keySetPointer = base,
                   *newKeySet = new KeySet(key, value);
            // TODO: refactor optimise
            while (keySetPointer->nextKeySet && (key != keySetPointer->mKey))
            {
                keySetPointer = keySetPointer->nextKeySet;
            }

            // newKeySet->nextKeySet = keySetPointer->nextKeySet;
            if (key == keySetPointer->mKey)
            {
                keySetPointer->mValue = value;
            }
            else
            {
                keySetPointer->nextKeySet = newKeySet;
                mSize++;
            }
        }
    }

    bool find(const K k) const
    {
        KeySet *keySetPointer = base;

        while (keySetPointer->nextKeySet && keySetPointer->mKey != k)
        {
            keySetPointer = keySetPointer->nextKeySet;
        }

        return (keySetPointer->mKey == k);
    }

    V get(const K k) const
    {
        KeySet *keySetPointer = base;

        while (keySetPointer->nextKeySet)
        {
            if (keySetPointer->mKey == k)
            {
                return keySetPointer->mValue;
            }
            keySetPointer = keySetPointer->nextKeySet;
        }
        cout << "\nNo value was found with that key. ";
        return V();
    }

    bool set(const K k, const V v) const
    {
        KeySet *keySetPointer = base;

        while (keySetPointer->nextKeySet)
        {

            if (keySetPointer->mKey == k)
            {
                keySetPointer->mValue = v;
                return true;
            }

            keySetPointer = keySetPointer->nextKeySet;
        }
        cout << "\nNo value was found with that key. ";
        return false;
    }

    bool remove(K k)
    {
        KeySet *keySetPointer = base;

        while (keySetPointer->nextKeySet)
        {
            if (keySetPointer->nextKeySet->mKey == k)
            {
                keySetPointer->nextKeySet = keySetPointer->nextKeySet->nextKeySet;
                mSize--;
                return true;
            }

            keySetPointer = keySetPointer->nextKeySet;
        }
        cout << "\nNo value was found with that key. ";
        return false;
    }

    void display() const
    {
        cout << "\nSize of map:  " << mSize << '\n';

        if (mSize != 0)
        {

            cout << base->mKey << " , " << base->mValue << '\n';

            KeySet *keySetPointer = base->nextKeySet;

            while (keySetPointer)
            {
                cout << keySetPointer->mKey << " , " << keySetPointer->mValue << '\n';
                keySetPointer = keySetPointer->nextKeySet;
            }
            cout << "\n";
        }

        /*
        if (mSize != 0)
        {
            KeySet *keySetPointer = base;
            for (int i = 0; i < mSize; i++)
            {
                cout << keySetPointer->mKey;
                cout << " , ";
                cout << keySetPointer->mValue;
                cout << "\n\n";

                if (keySetPointer->nextKeySet)
                {
                    keySetPointer = keySetPointer->nextKeySet;
                }
            }
        }
        */
    }

    int size()
    {
        return mSize;
    }
};

/**
 * Main
 *
 */
int main()
{

    Map<int, char> newMap(1, 'a');

    newMap.put(2, 'b');

    newMap.put(3, 'c');

    newMap.put(3, 'u');

    newMap.put(3, 'd');

    newMap.put(6, '3');

    newMap.put(4, 'i');

    newMap.display();

    cout << newMap.find(4);

    cout << "\n"
         << newMap.find(9);

    cout << "\n"
         << newMap.get(3);

    cout << "\n"
         << newMap.get(1);

    cout << "\n"
         << newMap.get(26);

    cout << "\n------------------\n";

    Map<int, char> emptyMap;

    cout << emptyMap.size();

    emptyMap.put(5, 'y');

    emptyMap.put(2, 'b');

    emptyMap.put(3, 'c');

    emptyMap.put(3, 'u');

    emptyMap.put(3, 'd');

    emptyMap.put(6, '3');

    emptyMap.put(4, 'i');

    emptyMap.display();

    cout << "\n"
         << emptyMap.find(4);

    cout << "\n"
         << emptyMap.find(9);

    cout << "\n"
         << emptyMap.get(3);

    cout << "\n"
         << emptyMap.get(1);

    cout << "\n\n------------------------\n\nTesting set method";

    emptyMap.set(2, 'h');

    emptyMap.display();

    emptyMap.set(49, 'h');

    cout << "\n\n------------------------\n\nTesting remove method";

    emptyMap.remove(4);
    emptyMap.display();

    emptyMap.remove(2);
    emptyMap.display();

    return 0;

    // int firstNumber = 1;
    // int* secondNumber = &firstNumber;

    // void* notApointer = &firstNumber;

    // cout << notApointer;
    /*
        cout << secondNumber << endl;

        (*secondNumber)++;

        cout << *secondNumber << endl;
        */

    /*


        cout << *secondNumber << endl;


        (*secondNumber)++;
        cout << *secondNumber << endl;
        */

    // cout << firstNumber;
}