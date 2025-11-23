//Taylor Dubois
//11/19/25

#include <iostream>
#include <fstream>
#include <vector>

int main(int argc, char* argv[]){
    if(argc != 2){
        std::cout << "Usage: ./banker <input_file>\n";
        return 1;
    }
    std::ifstream file(argv[1]);
    if(!file){
        std::cout << "Error opening input file.\n";
        return 1;
    }

    int P, R;
    file >> P >> R;

    std::vector<std::vector<int>> allocation(P, std::vector<int>(R));
    std::vector<std::vector<int>> max(P, std::vector<int>(R));
    std::vector<std::vector<int>> need(P, std::vector<int>(R));
    std::vector<int> available(R);
    std::vector<bool> finished(P, false);
    std::vector<int> safeSequence;
    int finishedCount = 0;

    //read allocation from input
    for(int i = 0; i < P; i++)
        for(int j = 0; j < R; j++)
            file >> allocation[i][j];
    //read max from input
    for(int i = 0; i < P; i++)
        for(int j = 0; j < R; j++)
            file >> max[i][j];
    //read available from input
    for(int i = 0; i < R; i++)
        file >> available[i];
    //get need
    for(int i = 0; i < P; i++){
        for(int j = 0; j < R; j++){
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    //Safety Check
    while(finishedCount < P){
        bool found = false;

        for(int i = 0; i < P; i++){
            if(!finished[i]){
                bool safe = true;

                for(int j = 0; j < R; j++){
                    if(need[i][j] > available[j]){
                        safe = false;
                        break;
                    }
                }
                if(safe){
                    //Pretend process finishes
                    for(int j = 0; j < R; j++)
                        available[j] += allocation[i][j];

                    safeSequence.push_back(i);
                    finished[i] = true;
                    finishedCount++;
                    found = true;
                }
            }
        }
        if(!found){
            std::cout << "System is not in a safe state.\n";
            return 0;
        }
    }
    std::cout << "System is in a safe state.\nThe safe sequence is: ";
    for(int i = 0; i < P; i++){
        std::cout << "P" << safeSequence[i];
        if(i != P - 1) std::cout << " -> ";
    }
    std::cout << std::endl;
    return 0;
}
