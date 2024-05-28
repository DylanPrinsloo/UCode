from datetime import datetime
import sqlite3


class Store:
    def __init__(self, db_file):
        self.conn = sqlite3.connect(db_file)
        self.cur = self.conn.cursor()
        self.create_tables()
        self.displayProducts()

    def create_tables(self):
        self.cur.execute('''CREATE TABLE IF NOT EXISTS Product (
                            product_id INTEGER PRIMARY KEY,
                            product_name TEXT NOT NULL,
                            product_price REAL NOT NULL,
                            product_quantity INTEGER NOT NULL)'''
                         )
        self.cur.execute("""CREATE TABLE IF NOT EXISTS Sales (
                            sale_id INTEGER PRIMARY KEY,
                            sale_date TEXT NOT NULL,
                            product_name TEXT NOT NULL,
                            sale_total REAL NOT NULL)"""
                         )
        self.conn.commit()

    def addProduct(self, name, price, quantity):
        self.cur.execute("INSERT INTO Product (product_name, product_price, product_quantity) VALUES (?, ?, ?)",
                         (name, price, quantity))
        self.conn.commit()

    def removeProduct(self, product_id):
        self.cur.execute("DELETE FROM Product WHERE product_id=?", (product_id,))
        self.conn.commit()

    def updateProduct(self, product_id, name, price, quantity):
        self.cur.execute("UPDATE Product SET product_name=?, product_price=?, product_quantity=? WHERE product_id=?",
                         (name, price, quantity, product_id))
        self.conn.commit()

    def displayProducts(self):
        self.cur.execute("SELECT * FROM Product")
        rows = self.cur.fetchall()
        for row in rows:
            print(row)

    def sellProduct(self, product_id, sale_date, sale_quantity):
        self.cur.execute("SELECT product_quantity FROM Product WHERE product_id=?", (product_id,))
        row = self.cur.fetchone()
        if row:
            quantity_available = row[0]
            if quantity_available >= sale_quantity > 0:
                total_price = self.get_product_price(product_id) * sale_quantity
                self.cur.execute("UPDATE Product SET product_quantity=? WHERE product_id=?",
                                 (quantity_available - sale_quantity, product_id))
                self.cur.execute("INSERT INTO Sales (sale_date, product_name, sale_total) VALUES (?, ?, ?)",
                                 (sale_date, self.get_product_name(product_id), total_price))
                self.conn.commit()
                print("Sale successful.")
            else:
                print("Invalid quantity to sell.")
        else:
            print("Product not found.")

    def get_product_price(self, product_id):
        self.cur.execute("SELECT product_price FROM Product WHERE product_id=?", (product_id,))
        row = self.cur.fetchone()
        if row:
            return row[0]
        else:
            return None

    def get_product_name(self, product_id):
        self.cur.execute("SELECT product_name FROM Product WHERE product_id=?", (product_id,))
        row = self.cur.fetchone()
        if row:
            return row[0]
        else:
            return None

    def __del__(self):
        self.conn.close()

def main():
    store = Store("store.db")

    while True:
        print("\n1. Add Product")
        print("2. Remove Product")
        print("3. Update Product")
        print("4. Display Products")
        print("5. Sell Product")
        print("6. Exit")

        choice = input("Enter your choice: ")

        if choice == '1':
            name = input("Enter a product name: ")
            price = float(input("Enter a product price: "))
            quantity = int(input("Enter a product quantity: "))
            store.addProduct(name, price, quantity)

        elif choice == '2':
            product_id = int(input("Enter product ID to remove: "))
            store.removeProduct(product_id)

        elif choice == '3':
            product_id = int(input("Enter product ID to update: "))
            name = input("Enter product name: ")
            price = float(input("Enter a product price: "))
            quantity = int(input("Enter a product quantity: "))
            store.updateProduct(product_id, name, price, quantity)

        elif choice == '4':
            store.displayProducts()
        elif choice == '5':
            product_id = int(input("Enter the product ID to sell: "))
            sale_date = datetime.now().strftime("%Y-%m-%d")
            sale_quantity = int(input("Enter a quantity to sell: "))
            store.sellProduct(product_id, sale_date, sale_quantity)

        elif choice == '6':
            print("Exiting.")
            break

        else:
            print("Invalid choice. Please try again.")

if __name__ =="__main__":
 main()
