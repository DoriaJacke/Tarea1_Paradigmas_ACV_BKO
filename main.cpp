#include <iostream>
#include <vector>
using namespace std;


//------------------------
// ** Clases
//------------------------

class Menu{
public:
    Menu();

    void inicioMenu();\
    void crearPreguntas();
    void crearItem();
    void borrarItem();
    void consultarItem();
    void buscarTaxonomia();
};

class Opcion{
private:
    int num;
    string opcion;

public:
    Opcion(int num, string opcion);

};

Opcion::Opcion(int num, std::string opcion) {
    this->num;
    this->opcion;
}


//========================
// Opción múltiple
//------------------------
class Opc_mult {

private:
    string encabezado;
    vector<Opcion*> Opciones;
    int opc_correcta;
    string taxonomia;
    int duracion;

public:
    Opc_mult(string encabezado, vector<Opcion *> Opciones, int opc_correcta, string taxonomia, int duracion);
    ~Opc_mult();
    string getEncabezado();
    Opcion* getOpciones();
    int getOpc_correcta();
    void setEncabezado(string encabezado);

};

//======================
// Verdadero y falso
//----------------------
class VyF {
private:
    string header;
    char answer;
    string justificacion;
    string taxonomia;
    int duracion;
public:
    //---------------------
    // Constructor
    VyF(string header, char answer,string justificacion,string taxonomia,int duracion);
    //---------------------
    // Destructor
    ~VyF();
    //---------------------
    // Declarando 'getter'
    int getnum_p();
    string getheader();
    char getanswer();
    //---------------------
    // Declarando 'setter'
    void setheader(string header);
    void setanswer(char answer);
};

vector<VyF*> preguntasVyF;
vector<Opc_mult*> preguntasMult;


class Item {
private:
    vector<VyF *> VerdaderoYFalso;
    vector<Opc_mult *> OpcionesMultiples;
public:
    Item(VyF *VF, Opc_mult *OM);

};

//-------------------------------------------------------------------------------------------------------------
//Constructores
Menu::Menu() {}

VyF::VyF(string header, char answer,string justificacion, string taxonomia, int duracion) {
    this->header = header;
    this->answer = answer;
    this->justificacion = justificacion;
    this->taxonomia = taxonomia;
    this->duracion = duracion;
}
Opc_mult::Opc_mult(string encabezado, vector<Opcion*> Opciones, int opc_correcta, string taxonomia, int duracion) {
    this->encabezado = encabezado;
    this->Opciones = Opciones;
    this->opc_correcta = opc_correcta;
    this->taxonomia= taxonomia;
    this->duracion=duracion;

}
//--------------------------------------------------------------------------------------------------------------
//Destructores



VyF::~VyF(){
    cout<<"Destruyendo Objeto Pregunta Verdadero y Falso"<<endl;
}
Opc_mult::~Opc_mult() {
    cout<<"Destruyendo Objeto Pregunta Opcion Multiple"<<endl;
}


//Getters y setters

//Def Setters
void VyF::setheader(string header){
    this->getheader()=header;
}

string VyF::getheader(){
    return this->header;
}
//---------------------------------------------------------------------------------------------------------------
//Metodos
void Menu::inicioMenu() {
    bool run = true;
    int opcion= -1;
    while(run){

        //print menu
        cout<<"Menu Principal: "<< endl;
        cout<<"1)Agregar Preguntas"<< endl;
        cout<<"2)Crear Item"<< endl;
        cout<<"3)Borrar Item"<< endl;
        cout<<"4)Consultar Item"<< endl;
        cout<<"5)Buscar por Taxonomia"<< endl;
        cout<<"0)Volver al menu\n"<< endl;


        //Ingreso Decicion;
        cout <<"Ingrese numero de la opcion: "<<endl;
        cin >> opcion;

        //Crear pregunta
        if (opcion==1){
            this->crearPreguntas();

        }

        //crear item
        if (opcion==2){
          //this->crearItem();

        }

        //borrar Item
        if (opcion==3){
           // this->borrarItem();

        }

        //consultar Item
        if (opcion==4){
           // this->consultarItem();
        }

        //buscar Taxonomia
        if (opcion==5){
            //this->buscarTaxonomia();
        }
        //Termino prueba
        if (opcion==0){
            run = false;
        }

        //Invalid
        if(opcion>5 || opcion<0){
            cout<<"Opcion Invalida, volviendo al menu"<< endl;
        }
    }
}

void Menu::crearPreguntas() {
    bool add = true;
    int preg= -1,res;
    while(add){

        //print menu
        cout<<"Tipos de pregunta:"<< endl;
        cout<<"1)Verdadero y Falso"<< endl;
        cout<<"2)Opcion Multiple"<< endl;
        cout<<"0)Volver al menu \n"<< endl;

        //Ingreso Decicion;
        cout <<"Ingrese opcion: "<<endl;
        cin >> res;
        preg = res;
        //Crear VyF
        if (preg==1){
            string header;
            char answer;
            string justificacion;
            string taxonomia;
            int duracion;

            cout <<"Ingrese encabezado: "<<endl;
            getline(cin>>ws, header);
            cout <<"Ingrese V o F: "<<endl;
            cin >> answer;
            while (answer!='F'&&answer!='f'&&answer!='V'&&answer!='v'){
                cout <<"Ingrese V o F: "<<endl;
                cin >> answer;
            }
            if(answer=='F'||answer=='f'){
                cout <<"Ingrese justificacion: "<<endl;
                getline(cin>>ws, justificacion);
            }
            else justificacion=" ";
            cout <<"Ingrese Nivel de Taxonomia: "<<endl;
            cin >> taxonomia;
            cout <<"Ingrese duracion en minutos: "<<endl;
            cin >> duracion;
            preguntasVyF.push_back(new VyF(header,answer,justificacion,taxonomia,duracion));
        }

        //Crear Seleccion Multiple
        if (preg==2){
            string encabezado;
            int opcion_correcta;
            string taxonomia;
            int duracion;
            int cont = 1;
            int seguir = 1;
            string opcion;
            vector<Opcion*> Opciones_pregunta;

            cout <<"Ingrese encabezado: "<<endl;
            getline(cin>>ws, encabezado);


            while (seguir==1){
                cout <<"Ingrese alternativa "<< cont <<endl;
                getline(cin>>ws, opcion);
                Opciones_pregunta.push_back(new Opcion(cont,opcion));
                if (cont>3) {
                    cout << "Desea agregar mas opciones:  Si(1) No(0)" << endl;
                    cin >> seguir;
                }
                cont++;


            }
            cout <<"Ingrese numero de la opcion correcta"<<endl;
            cin >> opcion_correcta;
            cout <<"Ingrese Nivel de Taxonomia: "<<endl;
            cin >> taxonomia;
            cout <<"Ingrese duracion en minutos: "<<endl;
            cin >> duracion;
            preguntasMult.push_back(new Opc_mult(encabezado, Opciones_pregunta, opcion_correcta, taxonomia,duracion));
        }

        //Termino de agregar preguntas
        if (preg==0){
            add = false;
        }

        //Invalid
        if(preg>2 || preg<0){
            cout<<"Opcion Invalida, volviendo al menu"<< endl;
        }
    }
}


//Crear Item
void Menu::crearItem() {
    int select;
    cout <<"Que tipo de item desea crear? 1)Opcion multiple 2)Verdader y falso"<<endl;
    cin >> select;
    if(select==1){
        for (int i=0; i <preguntasMult.size();i++) {

        }

    }



}





// Principal
int main() {
    Menu *menu1 = new Menu();
    menu1->inicioMenu();
};
