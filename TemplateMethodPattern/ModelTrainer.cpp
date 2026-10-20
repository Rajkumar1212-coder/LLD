#include <iostream>
#include<vector>
#include<string>
#include <stdexcept>
using namespace std;

class ModelTrainer{
    public:
    void trainPipeline (const string& dataPath){
        loadData(dataPath);
        preprocessData();
        trainModel();
        evaluateModel();
        saveModel();
    }
    protected:
    void loadData(const string& path){
        cout<<"Loading dataset from"<<path<<"\n";
    }
    virtual void preprocessData(){
        cout<<"Splitting into train/test and normalization\n";
    }
    virtual void trainModel()=0;
    virtual void evaluateModel()=0;
    virtual void saveModel() {
        cout << "Saving model to disk as default format\n";
    }
};
class NeuralNetworkTrainer : public ModelTrainer{
    protected:
    void trainModel() override {
        cout << "[NeuralNet] Training Neural Network for 100 epochs\n";
        // pseudo-code: forward/backward passes, gradient descent...
    }
    void evaluateModel() override {
        cout << "[NeuralNet] Evaluating accuracy and loss on validation set\n";
    }
    void saveModel() override {
        cout << "[NeuralNet] Serializing network weights to .h5 file\n";
    }
};
class DecisionTreeTrainer : public ModelTrainer {
protected:
   
    void trainModel() override {
        cout << "[DecisionTree] Building decision tree with max_depth=5\n";
        // pseudo-code: recursive splitting on features...
    }
    void evaluateModel() override {
        cout << "[DecisionTree] Computing classification report (precision/recall)\n";
    }
    
};
int main() {
    cout << "=== Neural Network Training ===\n";
    ModelTrainer* nnTrainer = new NeuralNetworkTrainer();
    nnTrainer->trainPipeline("data/images/");

    cout << "\n=== Decision Tree Training ===\n";
    ModelTrainer* dtTrainer = new DecisionTreeTrainer();
    dtTrainer->trainPipeline("data/iris.csv");

    return 0;
}