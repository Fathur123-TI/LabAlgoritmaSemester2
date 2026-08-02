#include <iostream>
#include <string>

using namespace std;

const int V = 7;
const int INF = 99999;

string kota[V] = {
    "Cibinong",
    "Cileubeut",
    "Tanah Sareal",
    "Bogor Tengah",
    "Bogor Utara",
    "Baranangsiang",
    "Tajur"
};

int graph[V][V];

void inisialisasi()
{
    for(int i = 0; i < V; i++)
    {
        for(int j = 0; j < V; j++)
        {
            if(i == j)
                graph[i][j] = 0;
            else
                graph[i][j] = INF;
        }
    }

    // Jalur pada graph
    graph[0][1] = 1;
    graph[1][2] = 1;
    graph[2][3] = 1;
    graph[3][6] = 1;

    graph[0][4] = 1;
    graph[4][5] = 1;
    graph[5][6] = 1;
}

void floydWarshall()
{
    int dist[V][V];

    for(int i = 0; i < V; i++)
    {
        for(int j = 0; j < V; j++)
        {
            dist[i][j] = graph[i][j];
        }
    }

    for(int k = 0; k < V; k++)
    {
        for(int i = 0; i < V; i++)
        {
            for(int j = 0; j < V; j++)
            {
                if(dist[i][k] != INF &&
                   dist[k][j] != INF &&
                   dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    cout << "PENCARIAN JALUR TERPENDEK PADA GRAPH\n\n";

    cout << "Posisi Awal : " << kota[0] << endl;
    cout << "Tujuan      : " << kota[6] << endl;

    cout << "\nJalur 1" << endl;
    cout << "Cibinong -> Cileubeut -> Tanah Sareal -> Bogor Tengah -> Tajur" << endl;
    cout << "Jumlah Jalur : 4 ruas" << endl;

    cout << "\nJalur 2" << endl;
    cout << "Cibinong -> Bogor Utara -> Baranangsiang -> Tajur" << endl;
    cout << "Jumlah Jalur : 3 ruas" << endl;

    cout << "\nJalur Terpendek" << endl;
    cout << "Cibinong -> Bogor Utara -> Baranangsiang -> Tajur" << endl;
    cout << "Total Jarak : " << dist[0][6] << " ruas" << endl;
}

int main()
{
    inisialisasi();
    floydWarshall();

    return 0;
}
