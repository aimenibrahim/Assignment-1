#include <iostream>
#include <string>
using namespace std;

struct Item
{
    string name;
    Item* next;
};

struct Location
{
    string name;
    Location* next;
    Item* items;
};

struct Section
{
    string name;
    Section* next;
    Location* locations;
};

struct Store
{
    string name;
    Store* next;
    Section* sections;
};

Store* stores = NULL;

void addStore(string name)
{
    Store* newStore = new Store;

    newStore->name = name;
    newStore->sections = NULL;
    newStore->next = stores;

    stores = newStore;
}

void addSection(string storeName, string sectionName)
{
    Store* store = stores;

    while (store != NULL && store->name != storeName)
        store = store->next;

    if (store == NULL)
        return;

    Section* newSection = new Section;

    newSection->name = sectionName;
    newSection->locations = NULL;
    newSection->next = store->sections;

    store->sections = newSection;
}

void addLocation(string storeName, string sectionName, string locationName)
{
    Store* store = stores;

    while (store != NULL && store->name != storeName)
        store = store->next;

    if (store == NULL)
        return;

    Section* section = store->sections;

    while (section != NULL && section->name != sectionName)
        section = section->next;

    if (section == NULL)
        return;

    Location* newLocation = new Location;

    newLocation->name = locationName;
    newLocation->items = NULL;
    newLocation->next = section->locations;

    section->locations = newLocation;
}

void addItem(string storeName, string sectionName,
             string locationName, string itemName)
{
    Store* store = stores;

    while (store != NULL && store->name != storeName)
        store = store->next;

    if (store == NULL)
        return;

    Section* section = store->sections;

    while (section != NULL && section->name != sectionName)
        section = section->next;

    if (section == NULL)
        return;

    Location* location = section->locations;

    while (location != NULL && location->name != locationName)
        location = location->next;

    if (location == NULL)
        return;

    Item* newItem = new Item;

    newItem->name = itemName;
    newItem->next = location->items;

    location->items = newItem;
}

void removeItem(string storeName, string sectionName,
                string locationName, string itemName)
{
    Store* store = stores;

    while (store != NULL && store->name != storeName)
        store = store->next;

    if (store == NULL)
        return;

    Section* section = store->sections;

    while (section != NULL && section->name != sectionName)
        section = section->next;

    if (section == NULL)
        return;

    Location* location = section->locations;

    while (location != NULL && location->name != locationName)
        location = location->next;

    if (location == NULL)
        return;

    Item* current = location->items;
    Item* previous = NULL;

    while (current != NULL)
    {
        if (current->name == itemName)
        {
            if (previous == NULL)
                location->items = current->next;
            else
                previous->next = current->next;

            delete current;
            return;
        }

        previous = current;
        current = current->next;
    }
}

void displaySectionItems(string storeName, string sectionName)
{
    Store* store = stores;

    while (store != NULL && store->name != storeName)
        store = store->next;

    if (store == NULL)
        return;

    Section* section = store->sections;

    while (section != NULL && section->name != sectionName)
        section = section->next;

    if (section == NULL)
        return;

    Location* location = section->locations;

    while (location != NULL)
    {
        cout << "Location: " << location->name << endl;

        Item* item = location->items;

        while (item != NULL)
        {
            cout << item->name << " ";
            item = item->next;
        }

        cout << endl;

        location = location->next;
    }
}

void displayStoreItems(string storeName)
{
    Store* store = stores;

    while (store != NULL && store->name != storeName)
        store = store->next;

    if (store == NULL)
        return;

    Section* section = store->sections;

    while (section != NULL)
    {
        cout << "\nSection: " << section->name << endl;

        displaySectionItems(storeName, section->name);

        section = section->next;
    }
}

int main()
{
    addStore("Store A");

    addSection("Store A", "Grocery");
    addSection("Store A", "Toys");

    addLocation("Store A", "Grocery", "Shelf 1");
    addLocation("Store A", "Grocery", "Shelf 2");
    addLocation("Store A", "Toys", "Shelf 3");

    addItem("Store A", "Grocery", "Shelf 1", "Milk");
    addItem("Store A", "Grocery", "Shelf 1", "Bread");
    addItem("Store A", "Grocery", "Shelf 2", "Apple");
    addItem("Store A", "Toys", "Shelf 3", "Car");

    cout << "Grocery Items:\n";
    displaySectionItems("Store A", "Grocery");

    cout << "\nAll Store Items:\n";
    displayStoreItems("Store A");

    cout << "\nAfter Removing Bread:\n";
    removeItem("Store A", "Grocery", "Shelf 1", "Bread");

    displayStoreItems("Store A");

    return 0;
}
