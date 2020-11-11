#include <iostream>
#include <string>
#include <algorithm>
#include <vector>



struct Tap {
    int temperature;
    int minFlow, maxFlow;

    bool operator < (const Tap& rhs) const
    {
        return (temperature < rhs.temperature);
    }
};

using namespace std;
int tapN;
vector<Tap> taps;


double minTemp(int flow) {
    double greedyFlow = 0, greedyTemp = 0;

    for(int i = 0; i < tapN && flow > 0; i++){  
        flow -= taps[i].minFlow;
        greedyFlow += taps[i].minFlow;
        greedyTemp += taps[i].temperature * taps[i].minFlow;
    }

    for(int i = 0; i < tapN && flow > 0; i++){
        int flowLeft = taps[i].maxFlow - taps[i].minFlow;
        int flowUsed = flowLeft < flow ? flowLeft : flow;

        flow -= flowUsed;
        greedyFlow += flowUsed;
        greedyTemp += taps[i].temperature * flowUsed;
    }

    return greedyTemp / greedyFlow;
}

double maxTemp(int flow) {
    double greedyFlow = 0, greedyTemp = 0;

    for(int i = 0; i < tapN && flow > 0; i++){  
        flow -= taps[i].minFlow;
        greedyFlow += taps[i].minFlow;
        greedyTemp += taps[i].temperature * taps[i].minFlow;
    }
    //cout << "1: greedyTemp & Flow " << greedyTemp << " " << greedyFlow << "\n";

    //cout << "mintemp for flow: " << flow << "\n";
    for(int i = tapN - 1; i >= 0 && flow > 0; i--){
        int flowLeft = taps[i].maxFlow - taps[i].minFlow;
        int flowUsed = flowLeft < flow ? flowLeft : flow;
        flow -= flowUsed;
        //cout << "Flow used: " << flowUsed << " at temperature " << taps[i].temperature << "\n"; 
        greedyFlow += flowUsed;
        greedyTemp += taps[i].temperature * flowUsed;
    }
   
    //cout << "2: greedyTemp & Flow " << greedyTemp << " " << greedyFlow << "\n";
    return greedyTemp / greedyFlow;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> tapN;
    taps.resize(tapN);
    int maxFlow = 0;
    int minFlow = 0;
    for(int i = 0; i < tapN; i++){
        cin >> taps[i].temperature >> taps[i].minFlow >> taps[i].maxFlow;
        minFlow += taps[i].minFlow;
        maxFlow += taps[i].maxFlow;
    }

    sort(taps.begin(), taps.end());

   
    
    int n;
    cin >> n;
    int temp, flow;
    for(int i = 0; i < n; i++){
        cin >> temp >> flow;
        //printf("recipe: t%i f%i, maxTemp: %f minTemp: %f, minFlow: %i, maxFlow: %i\n", temp, flow,  maxTemp(flow),  minTemp(flow), minFlow, maxFlow);
        if(flow >= minFlow && flow <= maxFlow && temp <= maxTemp(flow) && temp >= minTemp(flow)) 
            cout << "yes\n";
        else cout << "no\n";
    }
}