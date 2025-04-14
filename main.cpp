//-------------------------------------------------
// ** Inicialización
//-------------------------------------------------
#include <iostream>
#include <vector>
using namespace std;

//-------------------------------------------------
// ** Clases
//-------------------------------------------------
// * Opción
class Opcion{
private:
    int num;
    string opcion;
public:
    Opcion(int num, string opcion);
};

Opcion::Opcion(int num, string opcion) {
    this->num=num;
    this->opcion=opcion;
}
//-------------------------------------------------
// * Opción múltiple
class Opc_mult {
private:
    string encabezado;
    vector<Opcion*> Opciones;
    int opc_correcta;
    int taxonomia;
    int duracion;
public:
    Opc_mult(string encabezado, vector<Opcion *> Opciones, int opc_correcta, int taxonomia, int duracion);
    ~Opc_mult();

    string getEncabezado();
    vector<Opcion*> getOpciones();
    int getOpc_correcta();
    int getTax();
    int getduracion();
};
//-------------------------------------------------
// * Verdadero y falso
class VyF {
private:
    string header;
    char answer;
    string justificacion;
    int taxonomia;
    int duracion;
public:
    // Constructor
    VyF(string header, char answer,string justificacion, int taxonomia, int duracion);
    // Destructor
    ~VyF();
    //---------------------
    // Declarando 'getter'
    string getheader();
    char getanswer();
    string getJustificacion();
    int getTax();
    int getduracion();
};
//-------------------------------------------------
// * Item
class Item {
private:
    string nombre;
    vector<VyF*> VerdaderoYFalso;
    vector<Opc_mult *> OpcionesMultiples;
public:
    Item(string nombre,vector<VyF *>VF, vector<Opc_mult *>OM);
    string getNombre();
    vector<VyF*> getPVF();
    vector<Opc_mult*> getPOM();
};
//-------------------------------------------------
// * Menú
class Menu{
private:
    vector<Item*> items;
    vector<VyF*> preguntasVyF;
    vector<Opc_mult*> preguntasMult;
public:
    Menu();
    void inicioMenu();
    void crearPreguntas();
    void crearItem();
    void borrarItem();
    void consultarItem();
    void buscarTaxonomia();
    void DuracionTotal();
};
//-------------------------------------------------
// ** Constructores
//-------------------------------------------------
// * Item
Item::Item(string nombre,vector<VyF *>VF, vector<Opc_mult *>OM) {
    this->nombre = nombre;
    this->VerdaderoYFalso = VF;
    this->OpcionesMultiples = OM;
}
//-------------------------------------------------
// * Menú
Menu::Menu() {}
//-------------------------------------------------
// * Verdadero y falso
VyF::VyF(string header, char answer,string justificacion, int taxonomia, int duracion) {
    this->header = header;
    this->answer = answer;
    this->justificacion = justificacion;
    this->taxonomia = taxonomia;
    this->duracion = duracion;
}
//-------------------------------------------------
// * Opción múltiple
Opc_mult::Opc_mult(string encabezado, vector<Opcion*> Opciones, int opc_correcta, int taxonomia, int duracion) {
    this->encabezado = encabezado;
    this->Opciones = Opciones;
    this->opc_correcta = opc_correcta;
    this->taxonomia = taxonomia;
    this->duracion = duracion;
}
//-------------------------------------------------
// ** Destructores
//-------------------------------------------------
// * Verdadero y falso
VyF::~VyF(){
    cout<<"Destruyendo Objeto Pregunta Verdadero y Falso"<<endl;
}
//-------------------------------------------------
// * Opción múltiple
Opc_mult::~Opc_mult() {
    cout<<"Destruyendo Objeto Pregunta Opcion Multiple"<<endl;
}
//-------------------------------------------------
// ** Getters
//-------------------------------------------------
// * Verdadero y falso: getHeader
string VyF::getheader(){
    return this->header;
}
//-------------------------------------------------
// * Verdadero y falso: getAnswer
char VyF::getanswer(){
    return this->answer;
}
//-------------------------------------------------
// Verdadero y falso: getJustificacion
string VyF::getJustificacion(){
    return this->justificacion;
}
//-------------------------------------------------
// * Verdadero y falso: getTax
int VyF::getTax() {
    return this->taxonomia;
}
//-------------------------------------------------
// * Verdadero y falso: getDuracion
int VyF::getduracion(){
    return this->duracion;
}
//-------------------------------------------------
// * Opción múltiple: getEncabezado
string Opc_mult::getEncabezado() {
    return this->encabezado;
}
//-------------------------------------------------
// * Opción múltiple: getOpciones
vector<Opcion*> Opc_mult::getOpciones(){
    return this->Opciones;
}
//-------------------------------------------------
// * Opción múltiple: getOpc_correcta
int Opc_mult::getOpc_correcta(){
    return this->opc_correcta;
}
//-------------------------------------------------
// * Opción múltiple: getTax
int Opc_mult::getTax(){
    return this->taxonomia;
}
//-------------------------------------------------
// * Opción múltiple: getDuracion
int Opc_mult::getduracion(){
    return this->duracion;
}
//-------------------------------------------------
// * Ítem: getNombre
string Item::getNombre() {
    return this->nombre;
}
//-------------------------------------------------
// * Ítem: getPVF
vector<VyF*> Item::getPVF(){
    return this->VerdaderoYFalso;
}
//-------------------------------------------------
// * Ítem: getPOM
vector<Opc_mult*> Item::getPOM(){
    return this->OpcionesMultiples;
}
//-------------------------------------------------
// ** Métodos
//-------------------------------------------------
// * Menú
void Menu::inicioMenu() {
    bool run = true;
    int opcion = -1;
    while(run){

        // * Impresión de menú
        cout<<"Menu principal: "<< endl;
        cout<<"1) Agregar preguntas"<< endl;
        cout<<"2) Crear item"<< endl;
        cout<<"3) Borrar item"<< endl;
        cout<<"4) Consultar item"<< endl;
        cout<<"5) Buscar por taxonomia"<< endl;
        cout<<"6) Duracion total de la prueba segun los items"<< endl;
        cout<<"0) Finalizar prueba\n"<< endl;

        // * Ingreso decisión
        cout <<"Ingrese numero de la opcion: "<<endl;
        cin >> opcion;

        // Crear pregunta
        if (opcion==1){
            this->crearPreguntas();
        }

        // Crear ítem
        if (opcion==2){
            this->crearItem();
        }

        // Borrar ítem
        if (opcion==3){
            this->borrarItem();
        }

        // Consultar ítem
        if (opcion==4){
            this->consultarItem();
        }

        // Buscar taxonomía
        if (opcion==5){
            this->buscarTaxonomia();
        }

        // Duración total
        if (opcion==6){
            this->DuracionTotal();
        }

        // Término prueba
        if (opcion==0){
            run = false;
        }

        // Opción invalida
        if(opcion>6 || opcion<0){
            cout<<"Opcion Invalida, volviendo al menu"<< endl;
        }
    }
}
//-------------------------------------------------
// * Crear preguntas
void Menu::crearPreguntas() {
    bool add = true;
    int preg= -1,res;
    while(add){

        // Print menú
        cout<<"Tipos de pregunta:"<< endl;
        cout<<"1)Verdadero y Falso"<< endl;
        cout<<"2)Opcion Multiple"<< endl;
        cout<<"0)Volver al menu \n"<< endl;

        // Ingreso decición;
        cout <<"Ingrese opcion: "<<endl;
        cin >> res;
        preg = res;

        // Crear verdadero y falso
        if (preg==1){
            string header;
            char answer;
            string justificacion;
            int taxonomia;
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
            cout<<"Niveles de Taxonomia: "<< endl;
            cout<<"1) Crear "<< endl;
            cout<<"2) Evaluar"<< endl;
            cout<<"3) Analizar"<< endl;
            cout<<"4) Aplicar"<< endl;
            cout<<"5) Entender"<< endl;
            cout<<"6) Recordar\n"<< endl;
            cout <<"Ingrese el valor del nivel de Taxonomia: "<<endl;
            cin >> taxonomia;
            cout <<"Ingrese duracion en minutos: "<<endl;
            cin >> duracion;
            preguntasVyF.push_back(new VyF(header,answer,justificacion,taxonomia,duracion));
        }

        // Crear selección múltiple
        if (preg==2){
            string encabezado;
            int opcion_correcta;
            int taxonomia;
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
            cout<<"Niveles de Taxonomia: "<< endl;
            cout<<"1) Crear "<< endl;
            cout<<"2) Evaluar"<< endl;
            cout<<"3) Analizar"<< endl;
            cout<<"4) Aplicar"<< endl;
            cout<<"5) Entender"<< endl;
            cout<<"6) Recordar\n"<< endl;
            cout <<"Ingrese el valor del nivel de Taxonomia: "<<endl;
            cin >> taxonomia;
            cout <<"Ingrese duracion en minutos: "<<endl;
            cin >> duracion;
            preguntasMult.push_back(new Opc_mult(encabezado, Opciones_pregunta, opcion_correcta, taxonomia,duracion));
        }

        // Término de agregar preguntas
        if (preg==0){
            add = false;
        }

        // Inválido
        if(preg>2 || preg<0){
            cout<<"Opcion Invalida, volviendo al menu"<< endl;
        }
    }
}
//-------------------------------------------------
// * Crear ítem
void Menu::crearItem() {
    int select=-1;
    string nombre;
    while(select!=1 && select!=2) {
        cout << "Que tipo de item desea crear? 1)Verdader y falso 2)Opcion multiple" << endl;
        cin >> select;
    }
    cout << "Como desea llamar al Item?" << endl;
    getline(cin>>ws, nombre);
    int agregar;
    vector<Opc_mult *> itemmult;
    vector<VyF *> itemvyf;
    if (select == 2) {
        for (int i = 0; i < preguntasMult.size(); i++) {
            cout << "Desea agregar la pregunta: " << preguntasMult[i]->getEncabezado() << endl;
            cout << "1)Si 0)No" << endl;
            cin >> agregar;
            if (agregar == 1) {
                itemmult.push_back(new Opc_mult(preguntasMult[i]->getEncabezado(), preguntasMult[i]->getOpciones(),
                                                preguntasMult[i]->getOpc_correcta(), preguntasMult[i]->getTax(),
                                                preguntasMult[i]->getduracion()));
            }
        }
    }
    if (select == 1) {
        for (int i = 0; i < preguntasVyF.size(); i++) {
            cout << "Desea agregar la pregunta: " << preguntasVyF[i]->getheader() << endl;
            cout << "1)Si 0)No" << endl;
            cin >> agregar;
            if (agregar == 1) {
                itemvyf.push_back(new VyF(preguntasVyF[i]->getheader(), preguntasVyF[i]->getanswer(),
                                          preguntasVyF[i]->getJustificacion(), preguntasVyF[i]->getTax(),
                                          preguntasVyF[i]->getduracion()));
            }
        }
    }
    items.push_back( new Item(nombre,itemvyf,itemmult));
}
//-------------------------------------------------
// * Borrar ítem
void Menu::borrarItem(){
    int index;
    for (int i = 0; i < items.size(); i++){
        cout << i << ")" << items[i] -> getNombre() << endl;
    }
    cout << "\nIngrese el item que desea borrar:\n>";
    cin >> index;
    if (index < items.size() && index >= 0) {
        items.erase(items.begin() + index);
        cout << "Item eliminado." << endl;
    } else {
        cout << "Item no valido." << endl;
    }
}
//-------------------------------------------------
// * Consultar ítem
void Menu::consultarItem() {
    int opcion,cont=-1;

    for (int i = 0; i < items.size(); i++){
        cout<<i<<")"<<items[i]->getNombre() <<endl;
        cont++;
    }
    cout <<"Ingrese numero de la opcion: "<<endl;
    cin >> opcion;
    while (opcion>cont&&opcion<0){
        cout <<"Opcion invalida \nIngrese numero de la opcion: "<<endl;
        cin >> opcion;
    }
    for (int i = 0; i < items.size(); i++){
        if(opcion==i){
            cout<<"Este item tiene las preguntas con el siguiente encabezado: "<<endl;
            for (int j = 0; j < items[opcion]->getPOM().size(); j++){
                cout<<items[opcion]->getPOM()[j]->getEncabezado() <<endl;
            }
            for (int j = 0; j < items[opcion]->getPVF().size(); j++){
                cout<<items[opcion]->getPVF()[j]->getheader() <<endl;
            }
        }
    }
    cout<<"\n"<<endl;
}
//-------------------------------------------------
// * Consultar por taxonomía
void Menu::buscarTaxonomia(){
    int taxonomia;
    cout<<"Niveles de Taxonomia: "<< endl;
    cout<<"1) Crear" << endl;
    cout<<"2) Evaluar" << endl;
    cout<<"3) Analizar" << endl;
    cout<<"4) Aplicar" << endl;
    cout<<"5) Entender" << endl;
    cout<<"6) Recordar\n" << endl;
    cout <<"Ingrese el valor del nivel de taxonomia: "<<endl;
    cin >> taxonomia;

    for (int j = 0; j < preguntasMult.size(); j++){
        if(preguntasMult[j] -> getTax() == taxonomia){
            cout << preguntasMult[j]-> getEncabezado() << endl;
        }
    }
    for (int j = 0; j < preguntasVyF.size(); j++){
        if( preguntasVyF[j]->getTax() == taxonomia ){
            cout << preguntasVyF[j]-> getheader() << endl;
        }
    }
}
//-------------------------------------------------
// * Duración total
void Menu::DuracionTotal(){
    int duracion=0;
    for (int i = 0; i < items.size(); i++){
        for (int j = 0; j < items[i]->getPOM().size(); j++){
            duracion= duracion + items[i]->getPOM()[j]->getduracion();
        }
        for (int j = 0; j < items[i]->getPVF().size(); j++){

            duracion = duracion + items[i]->getPVF()[j]->getduracion();
        }
    }
    cout<<"La prueba tiene duracion de "<< duracion << " minutos respecto a sus items."<<endl;
}
//-------------------------------------------------
// ** Principal
//-------------------------------------------------
int main() {
    Menu *menu1 = new Menu();
    menu1->inicioMenu();
}
//-------------------------------------------------