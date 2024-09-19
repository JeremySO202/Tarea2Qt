#include <QApplication>
#include <QMainWindow>

#include "lib/qcustomplot.h"
#include "ListaSimple.h"
#include "sorts.h"

ListaSimple generarListaInvertida(int N) {
    ListaSimple lista;
    for (int i = 1; i <= N; i++) {
        lista.insertarAlInicio(i);
    }
    return lista;
}

ListaSimple generarListaOrdenada(int N) {
    ListaSimple lista;
    for (int i = N; i >= 1; i--) {
        lista.insertarAlInicio(i);
    }
    return lista;
}

ListaSimple generarListaAleatoria(int N) {
    std::vector<int> elementos;
    for (int i = 1; i <= N; i++) {
        elementos.push_back(i);
    }
    std::random_shuffle(elementos.begin(), elementos.end());

    ListaSimple lista;
    for (int elem : elementos) {
        lista.insertarAlInicio(elem);
    }
    return lista;
}

int main(int argc, char *argv[]) {
    //El tiempo no me dio para mas, solo logre poner el mejor caso del bubblesort
    int MAX = 2000;

    QApplication app(argc, argv);
    QMainWindow window;
    window.setGeometry(100, 100, 1000, 600);

    QCustomPlot *customPlot = new QCustomPlot(&window);
    customPlot->setGeometry(10, 10, 780, 580);

    //Bubblesort best case
    QVector<double> bubbleSortTimesBCE,bubbleSortTimesBCT;
    QVector<double> listSizes;

    for (int N = 10; N <= MAX; N += 10) {
        ListaSimple listaOrdenada = generarListaOrdenada(N);

        auto start = std::chrono::high_resolution_clock::now();
        bubbleSort(listaOrdenada, N);
        auto end = std::chrono::high_resolution_clock::now();

        listSizes.push_back(N);//tamano
        bubbleSortTimesBCT.push_back(N);//caso teorico
        bubbleSortTimesBCE.push_back(std::chrono::duration_cast<std::chrono::microseconds>(end - start).count());//caso experimental
    }
    customPlot->addGraph();
    customPlot->graph(0)->setData(listSizes, bubbleSortTimesBCE);
    customPlot->graph(0)->setPen(QPen(Qt::blue));

    customPlot->addGraph();
    customPlot->graph(1)->setData(listSizes, bubbleSortTimesBCT);
    customPlot->graph(1)->setPen(QPen(Qt::red));


    // Configurar ejes
    customPlot->xAxis->setLabel("Tamaño de la lista");
    customPlot->yAxis->setLabel("Tiempo (microsegundos)");
    customPlot->xAxis->setRange(0, MAX);
    customPlot->yAxis->setRange(0, *std::max_element(bubbleSortTimesBCE.begin(), bubbleSortTimesBCE.end()));

    QCheckBox *checkBoxBubbleSort = new QCheckBox("Mejor caso BubbleSort ", &window);
    checkBoxBubbleSort->setGeometry(850, 50, 150, 30);

// Conectar los checkboxes con funciones de mostrar/ocultar
    QObject::connect(checkBoxBubbleSort, &QCheckBox::toggled, [=](bool checked) {
        customPlot->graph(0)->setVisible(checked);
        customPlot->graph(1)->setVisible(checked);
        customPlot->replot();  // Refrescar la gráfica
    });



    //varas finales

    checkBoxBubbleSort->setChecked(true);


    customPlot->replot();

    window.show();
    return app.exec();
}
