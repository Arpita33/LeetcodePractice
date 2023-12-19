#include<iostream>
#include<vector>
#include<map>
#include<set>
//#include<priority_queue>
using namespace std;
class Food
{
    public:
    int foodrating;
    string foodname;
    string foodcuisine;

    Food(string name, string cuisine, int rating)
    {
        foodrating = rating;
        foodname = name;
        foodcuisine = cuisine;
    }
    Food(const Food& f)
    {
        foodrating = f.foodrating;
        foodname = f.foodname;
        foodcuisine = f.foodcuisine;
    }
    bool operator<(const Food& other) const {
        // If food ratings are same sort on the basis of their name. (lexographically smaller name food will be on top)
        if (foodrating == other.foodrating) {
            return foodname < other.foodname;
        }
        // Sort on the basis of food rating. (bigger rating food will be on top)
        return foodrating > other.foodrating;
    }
    Food& operator=(const Food & rhs)
    {
        
        //cout << "Backpack's assignment operator. " << std::endl;

        return *this;
    }

};
ostream& operator<<(ostream& COUT, Food& food)
{
    COUT<<food.foodname<<", "<<food.foodcuisine<<", "<<food.foodrating<<endl;
    return COUT;
}
class FoodRatings{
//public:
    map<string, Food> food_rating_map;
    map<string, set<Food> > cuisine_food_map;
    public:
   FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings)
    {
        for(int i=0; i<foods.size(); i++)
        {
            Food food(foods[i],cuisines[i],ratings[i]);
            food_rating_map.insert(make_pair(foods[i], food));
            cuisine_food_map[cuisines[i]].insert(food);
        }

    }
    void changeRating(string food, int newRating) {

        //cout << food << endl;
        Food& fooditem = food_rating_map.at(food);
        //cout<<fooditem.foodname<<endl;
        cuisine_food_map[fooditem.foodcuisine].erase(fooditem);
        fooditem.foodrating = newRating;
        cuisine_food_map[fooditem.foodcuisine].insert(fooditem);
    }
    string highestRated(string cuisine) {
        return cuisine_food_map.at(cuisine).begin()->foodname;
    }

    void print_food_rating_map()
    {
        map<string, Food>::iterator it = food_rating_map.begin();
 
        // Iterate through the map and print the elements
        while (it != food_rating_map.end()) {
            cout << "Key: " << it->first
                << ", Value: " << it->second << endl;
            ++it;
        }
    }


};


int main()
{
    // set<Food> foodset;
    // foodset.insert(Food("kimchi", "japanese", 2));
    // foodset.insert(Food("tres-leches", "italian", 10));
    // foodset.insert(Food("noodles", "chinese",5));
    // foodset.insert(Food("biriyani","bangladeshi", 10));
    // for (auto& food : foodset) {
    //     std::cout << food.foodname << ' ' << food.foodrating<<endl;
    // }
    string foods[6] = {"kimchi", "miso", "sushi", "moussaka", "ramen", "bulgogi"};
    string cuisines[6] = {"korean", "japanese", "japanese", "greek", "japanese", "korean"};
    int ratings[6] = {9, 12, 8, 15, 14, 7};
    vector<string> foods1;
    vector<string> cuisines1;
    vector<int> ratings1;
    for(int i=0; i<6;i++)
    {
        foods1.push_back(foods[i]);
        cuisines1.push_back(cuisines[i]);
        ratings1.push_back(ratings[i]);
    }
    // map<string, Food> test;
    // test["A"] = Food("A","A",1);
    // cout<<test["A"]<<endl;
    FoodRatings fr= FoodRatings(foods1, cuisines1, ratings1);
    //fr.print_food_rating_map();
    cout<<fr.highestRated("japanese")<<endl;
    
    fr.changeRating("sushi", 20);
    cout<<fr.highestRated("japanese");
    //cout<<" --------------------- "<<endl;
    //fr.print_food_rating_map();


    
    
}

