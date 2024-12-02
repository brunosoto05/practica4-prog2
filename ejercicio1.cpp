#include <iostream>
using namespace std;

// Estructura para representar un punto
struct Punto {
    double x; // Coordenada X
    double y; // Coordenada Y
};

// Función para calcular la orientación de tres puntos
int orientacion(const Punto& p, const Punto& q, const Punto& r) {
    double val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0; 
    return (val > 0) ? 1 : -1; 
}

bool puntoEnSegmento(const Punto& p, const Punto& q, const Punto& r) {
    return (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
            q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y));
}

int determinarInterseccion(const Punto& p1, const Punto& q1, const Punto& p2, const Punto& q2) {
    int o1 = orientacion(p1, q1, p2);
    int o2 = orientacion(p1, q1, q2);
    int o3 = orientacion(p2, q2, p1);
    int o4 = orientacion(p2, q2, q1);

    if (o1 != o2 && o3 != o4) return 1;

    if (o1 == 0 && puntoEnSegmento(p1, p2, q1)){
        return 0;
    }
    else if (o2 == 0 && puntoEnSegmento(p1, q2, q1)){
        return 1;
    } 
    else if (o3 == 0 && puntoEnSegmento(p2, p1, q2)) {
        return 1;
    }
   else if (o4 == 0 && puntoEnSegmento(p2, q1, q2)){

    return 1;
   }

    else if(o1 == o2 && o3 == o4){

    return -1;
    }
}

int determinarRelacion(const Punto& p1, const Punto& q1, const Punto& p2, const Punto& q2) {
    double m1 = (q1.y - p1.y) / (q1.x - p1.x); 
    double m2 = (q2.y - p2.y) / (q2.x - p2.x); 

    if (m1 * m2 == -1) return 1;

    if (m1 == m2) return 0;

    return -1;
}

int main() {
    Punto p1, q1, p2, q2;

    cout << "Ingrese las coordenadas de la primera línea (x1 y1 x2 y2): ";
    cin >> p1.x >> p1.y >> q1.x >> q1.y;
    cout << "Ingrese las coordenadas de la segunda línea (x3 y3 x4 y4): ";
    cin >> p2.x >> p2.y >> q2.x >> q2.y;

    int resultadoInterseccion = determinarInterseccion(p1, q1, p2, q2);
    if (resultadoInterseccion == 1) {
        cout << "Las líneas se cruzan." << endl;
    } else if (resultadoInterseccion == 0) {
        cout << "Las líneas son paralelas." << endl;
    } else {
        cout << "Las líneas no se cruzan ni son paralelas." << endl;
    }
    int resultadoRelacion = determinarRelacion(p1, q1, p2, q2);
    if (resultadoRelacion == 1) {
        cout << "Las líneas son perpendiculares." << endl;
    } else if (resultadoRelacion == 0) {
        cout << "Las líneas son paralelas." << endl;
    } else {
        cout << "Las líneas no son perpendiculares ni paralelas." << endl;
    }

    return 0;
}
