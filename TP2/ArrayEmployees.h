
typedef struct{
 int id;
 char name[51];
 char lastName[51];
 float salary;
 int sector;
 int isEmpty;
}eEmployee;

/** \brief Se utiliza esta funcion para inicializar el empleado
 * Se pone en 1 si esta ocupada la posicion
 * \param eEmployee empleado [] es el array de empleados de la estructura
 * \param int len es la cantidad del array
 * \return no devuelve nada
 */
void initEmployees(eEmployee empleado[], int len);

//--------------------------------------------------------------------------

/** \brief Se utiliza para agregar un empleado
 *
 * \param eEmployee empleado []
 * \param int cantidad
 * \return no devuelve nada
 *
 */

void addEmployee (eEmployee empleado[], int cantidad);
//--------------------------------------------------------------------------


/** \brief Muestra un solo empleado
 *
 * \param eEmployee empleado
 * \param -
 * \return no devuelve nada
 *
 */

void mostrarEmpleado(eEmployee empleado);
//--------------------------------------------------------------------------


/** \brief Busca un empleado
 *
 * \param eEmployee empleado[]
 * \param int cantidad
 * \return no devuelve nada
 *
 */

void findEmployeeById(eEmployee empleado[], int cantidad);
//--------------------------------------------------------------------------

/** \brief Muestra todos los empleados cargados
 *
 * \param eEmployee empleado []
 * \param int cantidad
 * \return no devuelve nada
 *
 */

void printEmployees (eEmployee empleado [], int cantidad);
//--------------------------------------------------------------------------

/** \brief Modifica un empleado
 *
 * \param eEmployee empleado[]
 * \param int cantidad
 * \return no deuelve nada
 *
 */

void modificarEmpleado (eEmployee empleado[], int cantidad);
//--------------------------------------------------------------------------

/** \brief Elimina un empleado
 *
 * \param eEmployee empleado[]
 * \param int cantidad
 * \return no devuelve nada
 *
 */

void removeEmployee (eEmployee empleado [], int cantidad);
//--------------------------------------------------------------------------

/** \brief Ordena los empleados por apellido y nombre
 *
 * \param eEmployee empleado[]
 * \param int cantidad
 * \return no devuelve nada
 *
 */

void sortEmployees (eEmployee empleado[], int cantidad);
//--------------------------------------------------------------------------
/** \brief Calcula el total de sueldos de los empleados, el promedio de ellos y la cantidad
 *
 * \param eEmployee empleado[]
 * \param int cantidad
 * \return no devuelve nada
 *
 */

void promedioEmpleados (eEmployee empleado[], int cantidad);
