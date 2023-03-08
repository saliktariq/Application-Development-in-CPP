#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Product{
	private:
		int pid;
		string pname;
		double price;
		int catId;
		
	public:
		int getPID () const{
			return pid;
		}
		
		void setPID(int pid){
			this->pid = pid;
		}
		
		string getPName() const{
			return pname;
		}
		
		void setPName(string name){
			this->pname = name;
		}
		
		double getPrice() const{
			return price;
		}
		
		void setPrice(double price){
			this->price = price;
		}
		int getCatId() const{
			return catId;
		}
		void setCatId(int catId){
			this->catId = catId;
		}
		
		Product(): pid(0), pname(""), price(0.0), catId(0){}
};



class Category{
	private:
		int catId;
		string catName;

		
	public:
		int getCatId () const{
			return catId;
		}
		
		void setCatId(int catId){
			this->catId = catId;
		}
		
		string getCatName() const{
			return catName;
		}
		
		void setCatName(string name){
			this->catName = name;
		}

		Category(): catId(0), catName(""){}
};

class CategoryList {
private:
    vector<Category> categories;
    static CategoryList *instance;

public:
    static CategoryList *getInstance() {
        if (!instance) {
            instance = new CategoryList;
        }
        return instance;
    }

    void addCategory(Category category) {
        if (searchCategory(category.getCatId()) == nullptr) {
            categories.push_back(category);
            cout << "Category added successfully!" << endl;
        } else {
            cout << "Category with the given ID already exists." << endl;
        }
    }

    vector<Category> getCategories() const {
        return categories;
    }
    
    Category *searchCategory(int catId) {
        for (auto &category : categories) {
            if (category.getCatId() == catId) {
                return &category;
            }
        }
        return nullptr;
    }
};

CategoryList *CategoryList::instance = nullptr;


class ProductList {
private:
    vector<Product> products;
    static ProductList *instance;

public:
    static ProductList *getInstance() {
        if (!instance) {
            instance = new ProductList;
        }
        return instance;
    }

	void addProduct(Product product) {
	    CategoryList *categoryList = CategoryList::getInstance();
	    Category *category = categoryList->searchCategory(product.getCatId());
	    if (category) {
	        products.push_back(product);
	        cout << "Product added successfully!" << endl;
	    } else {
	        cout << "Category not found. Please add the category first." << endl;
	    }
	}


    vector<Product> getProducts() const {
        return products;
    }
    
    Product *searchProduct(int pid) {
    for (auto &product : products) {
        if (product.getPID() == pid) {
            return &product;
        }
    }
    return nullptr;
    }
};

ProductList *ProductList::instance = nullptr;


int main() {
    CategoryList *categoryList = CategoryList::getInstance();
    ProductList *productList = ProductList::getInstance();

    int choice = 0;

    do {
        cout << "Menu:" << endl;
        cout << "1. Add Category" << endl;
        cout << "2. Add Product" << endl;
        cout << "3. Search Category" << endl;
        cout << "4. Search Product" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Category category;
                int catId;
                string catName;

                cout << "Enter category ID: ";
                cin >> catId;
                category.setCatId(catId);

                cout << "Enter category name: ";
                cin >> catName;
                category.setCatName(catName);

                categoryList->addCategory(category);

                break;
            }
            case 2: {
                Product product;
                int pid, catId;
                string pname;
                double price;

                cout << "Enter product ID: ";
                cin >> pid;
                product.setPID(pid);

                cout << "Enter product name: ";
                cin >> pname;
                product.setPName(pname);

                cout << "Enter product price: ";
                cin >> price;
                product.setPrice(price);

                cout << "Enter product category ID: ";
                cin >> catId;
                product.setCatId(catId);

                productList->addProduct(product);

                break;
            }
            case 3: {
                int catId;
                cout << "Enter category ID to search: ";
                cin >> catId;
                Category *category = categoryList->searchCategory(catId);
                if (category) {
                    cout << "Category found: " << category->getCatName() << endl;
                } else {
                    cout << "Category not found." << endl;
                }
                break;
            }
            case 4: {
                int pid;
                cout << "Enter product ID to search: ";
                cin >> pid;
                Product *product = productList->searchProduct(pid);
                if (product) {
                    cout << "Product found: " << product->getPName() << endl;
                } else {
                    cout << "Product not found." << endl;
                }
                break;
            }
            case 5: {
                break;
            }
            default: {
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        }

    } while (choice != 5);

    return 0;
}

