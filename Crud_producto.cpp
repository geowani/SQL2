#include<iostream>
#include<mysql.h>
#include<mysql_error.h>
#include<locale.h>

using namespace std;
	class conne{
		
		public:
		MYSQL *obj;
		
		char* conectar(conectar,"localhost","usr_empresa", "Empres@123", "db_empresa.producto", 3306, NULL,0 ){
			
				if(!(obj=mysql_init(0)))
					{
						return "Error Create Objeto";
					}
					if(!mysql_real_connect("localhost","usr_empresa", "Empres@123", "db_empresa.producto", 3306, NULL,0)
					{
						return (char*)mysql_error(obj);
					}else
					{
						return "==========>> Base de Datos en Uso <<==========";
					}
		}
		
		void desconectar(){
			mysql_close(obj);
		}
	};
	
	conne conexion;
	
	struct stempresa{
	char idmarca[6];
	char marcas[20];
	
	}empresa;
	
	class clproductros{
		public:
			char *resultado;
			void insertar(struct stempresa ){
				try{
				conexion.conectar("localhost","usr_empresa","Empres@123","db_empresa.producto");
				char *consulta;
				char sentencia[]="INSERT INTO ALUMNO (ID,NOMBRE) VALUES (\'%s\',\'%s\',\'%s\')";
				consulta=new char[strlen(sentencia)+sizeof(stalumno)]-sizeof(int);
				sprintf(consulta,sentencia,id.marca, marcas);
				int aux=mysql_query(conexion.obj,consulta);
				if(!aux==0){
					throw mysql_error(conexion.obj);
				}
				resultado="Registro Ingresado Correctamente\n";
				}catch(const char* msg){
					cout<<msg;
					conexion.desconectar();
				}
			}
			
			void modificar(struct stproducto){
				try{
				conexion.conectar("localhost","usr_empresa","Empres@123","db_empresa.producto";
				char *consulta;
				char sentencia[]="UPDATE ALUMNO SET NOMBRE=\'%s\',PATERNO=\'%s\' wHERE ID=\'%s\'";
				consulta=new char[strlen(sentencia)+sizeof(stempresa)]-sizeof(int);
				sprintf(consulta,sentencia,id.marca, marcas);
				int aux=mysql_query(conexion.obj,consulta);
				if(!aux==0){
					throw mysql_error(conexion.obj);
				}
				resultado="Registro Modificado\n";
				}catch(const char* msg){
					cout<<msg;
					conexion.desconectar();
				}
			}
			
			void eliminar(struct stproducto){
				try{
				conexion.conectar("localhost","usr_empresa","Empres@123","db_empresa.producto");
				char *consulta;
				char sentencia[]="DELETE from marca WHERE ID=\'%s\'";
				consulta=new char[strlen(sentencia)+sizeof(stempresa)]-sizeof(int);
				sprintf(consulta,sentencia,marca.id);
				int aux=mysql_query(conexion.obj,consulta);
				if(!aux==0){
					throw mysql_error(conexion.obj);
				}
				resultado="Registro ELiminado Correctamente\n";
				}catch(const char* msg){
					cout<<msg;
					conexion.desconectar();
				}
			}
			
			void mostrar(){
				   MYSQL           *objDatos;
				   MYSQL_RES       *res;
				   MYSQL_ROW        row;
				   MYSQL_FIELD     *columna;
				   int              i, j, k, l;
				   unsigned long   *lon;
				   MYSQL_ROW_OFFSET pos;
				   if(!(objDatos = mysql_init(0))) {
				      cout<<"Error Objeto"<<endl;
				      rewind(stdin);
				      getchar();	      
					}
				   if(!mysql_real_connect(objDatos,"localhost", "usr_empresa", "Empres@123", "db_empresa.producto", 3306, NULL, 0)) {
				      cout<<"Error BD"<<MYSQL_PORT<<" Error: "<<mysql_error(objDatos)<<endl;
				      mysql_close(objDatos);
				      rewind(stdin);
				      getchar();
				   }
				   if(mysql_select_db(objDatos, "db_empresa.prodcuto")) {
				      cout<<mysql_error(objDatos)<<endl;
				      mysql_close(objDatos);
				      rewind(stdin);
				      getchar();
				   }
				   if(mysql_query(objDatos, "SELECT * FROM marca")) {
				      cout<<mysql_error(objDatos)<<endl;
				      mysql_close(objDatos);
				      rewind(stdin);
				      getchar();
				   }
				if((res=mysql_store_result(objDatos))){
					i=(int)mysql_num_rows(res);
					j=(int)mysql_num_fields(res);
					cout<<endl<<"		Datos Generales"<<endl;
					l=1;
					for(l=0;l<i;l++){
						row=mysql_fetch_row(res);
						lon=mysql_fetch_lengths(res);
						cout<<endl;
						for(k=0;k<j;k++){
						cout<<"	"<<((row[k]==NULL)?"NULL":row[k])<<"	";
					}
				}cout<<endl;
			    mysql_free_result(res);
			   }
			   mysql_close(objDatos);
			   rewind(stdin);
			   cout<<endl;
			}
			
	};
	
	void salir(){
		cout<<"Programa Finalizado\n";
	}
	
	void menu(){
		int opcion;
		clalumno op;
		cout<<"Presentado por: Lester Estrada\n";
		do{
		cout<<"---------------------------------------------------------------\n";
		cout<<"                  +------------------------+"<<endl;
		cout<<"                  |          Menu          |"<<endl;
		cout<<"                  +------------------------+"<<endl;
		cout<<"                  | Seleccione una Opción  |"<<endl;
		cout<<"                  | 1.- Crear Registros    |"<<endl;
		cout<<"                  | 2.- Eliminar Registros |"<<endl;
		cout<<"                  | 3.- Modificar Registros|"<<endl;
		cout<<"                  | 4.- Ver Registros      |"<<endl;
		cout<<"                  | 5.- Salir              |"<<endl;
		cout<<"                  +------------------------+"<<endl;
		cout<<"---------------------------------------------------------------"<<endl;
		
		clalumno x;
		cin>>opcion;
		
		switch(opcion){
				case 1:		
					cout<<"Ingrese Datos  \n";
					cout<<"Ingrese IDmarcas : ";
					cin>>id.marca;
					cout<<"Ingrese marca: ";
					cin>>marca;
					op.insertar(alu);
					cout<<op.resultado;
				break;
				
				case 2:		
					clalumno op;
					cout<<"Ingrese Código  a Eliminar: ";
					cin>>alu.id;
					op.eliminar(alu);
					cout<<op.resultado;
				break;
				
				case 3:
					cout<<"Modificar Datos \n";
					cout<<"Ingrese ID : ";
					cin>>alu.id;
					cout<<"\nModificará Registros con ID "<<alu.id<<endl;
					cout<<"\nIngrese Nuevo Nombre: ";
					cin>>alu.nombre;
					cout<<"Ingrese Nuevo Apellido Paterno: ";
					cin>>alu.paterno;
					op.modificar(alu);
					cout<<op.resultado;
				break;
				
				case 4:
					op.mostrar();
					
				break;
				case 5: salir();
				break;
				default:
				cout<<"Opción Incorrecta\n";	
		}
	}while(opcion!=5);
	}
	
int main() {
	setlocale(LC_CTYPE,"Spanish");
	menu();
	return 0;
}
