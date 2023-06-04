#include <iostream>
#include <vector>
#include <array> 
using namespace std;

class Hamburguesa1{
    public:
    std::vector<std::string> parts_;
    void Mostrar()const{
        cout << "Ingredientes: ";
        for (size_t i=0;i<parts_.size();i++){
            if(parts_[i]== parts_.back()){
                cout << parts_[i]<<".";
            }else{
                cout << parts_[i] << ", ";
            }
        }
        cout << "\n\n"; 
    }
};


class Hamburguesa{
    public:
    virtual ~Hamburguesa(){}
    virtual void IngredienteA() const =0;
    virtual void IngredienteB() const =0;
    virtual void IngredienteC() const =0;
    virtual void IngredienteD() const =0;
    virtual void IngredienteE() const =0;
    virtual void IngredienteF() const =0;
};

class ConcretaHamburguesa1 : public Hamburguesa{
    private:
        Hamburguesa1* hamburguesa;
   
    public:
        ConcretaHamburguesa1(){
            this->Reset();
        }
        ~ConcretaHamburguesa1(){
            delete hamburguesa;
        }

        void Reset(){
            this->hamburguesa= new Hamburguesa1();
        }
        void IngredienteA()const override{
            this->hamburguesa->parts_.push_back("Pollo");
        }

        void IngredienteB()const override{
            this->hamburguesa->parts_.push_back("Carne");
        }
        void IngredienteC()const override{
            this->hamburguesa->parts_.push_back("Tocino");
        }

        void IngredienteD()const override{
            this->hamburguesa->parts_.push_back("Tomate");
        }
        void IngredienteE()const override{
            this->hamburguesa->parts_.push_back("Queso");
        }
        void IngredienteF()const override{
            this->hamburguesa->parts_.push_back("Papas Fritas");
        }      
        


        Hamburguesa1* GetProduct() {
            Hamburguesa1* result= this->hamburguesa;
            this->Reset();
            return result;
        }
};

class Director{
    
    private:
        Hamburguesa* hamburguesa;
   
    public:
    void set_hamburguesa(Hamburguesa* hamburguesa){
        this->hamburguesa=hamburguesa;
    }

    void PrepararHamburguesaDefault(){
        this->hamburguesa->IngredienteA();
        this->hamburguesa->IngredienteD();
        this->hamburguesa->IngredienteF();
    }
    
    void PrepararHamburguesaCompleta(){
        this->hamburguesa->IngredienteA();
        this->hamburguesa->IngredienteD();
        this->hamburguesa->IngredienteE();
        this->hamburguesa->IngredienteF();
    }
};

void Cliente(Director& director)
{
    ConcretaHamburguesa1* hamburguesa = new ConcretaHamburguesa1();
    director.set_hamburguesa(hamburguesa);
    std::cout << "Hamburguesa basica:\n"; 
    director.PrepararHamburguesaDefault();
    
    Hamburguesa1* p= hamburguesa->GetProduct();
    p->Mostrar();
    delete p;

    std::cout << "Hamburguesa completa:\n"; 
    director.PrepararHamburguesaCompleta();

    p= hamburguesa->GetProduct();
    p->Mostrar();
    delete p;
    std::cout << "Hamburguesa por eleccion:\n";
    hamburguesa->IngredienteB();
    hamburguesa->IngredienteF();
    p=hamburguesa->GetProduct();
    p->Mostrar();
    delete p;

    delete hamburguesa;
}

int main(){
    Director* director= new Director();
    Cliente(*director);
    delete director;
    return 0;    
}