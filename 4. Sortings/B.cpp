
#include <iostream>
#include <bits/stdc++.h>

using ll = long long;
static ll ans = 0;
using namespace std;

static vector<ll> leftHalf(const vector<ll>& arr){
    return {arr.begin(), arr.begin() + arr.size() / 2};
}

static vector<ll> rightHalf(const vector<ll>& arr){
    return {arr.begin() + arr.size() / 2, arr.end()};
}

static vector<ll> merge(vector<ll> arr1, vector<ll> arr2){
    if (arr2.size() == 1){
        if (arr1.size() == 1){
            if (arr1[0] <= arr2[0]){
                return {arr1[0], arr2[0]};
            } else {
                ans += 1;
                return {arr2[0], arr1[0]};
            }
        } else {
            return {arr2[0]};
        }
    }

    arr1 = merge(leftHalf(arr1), rightHalf(arr1));
    arr2 = merge(leftHalf(arr2), rightHalf(arr2));

    ll i = 0;
    ll j = 0;
    vector<ll> merged;


    while (i < arr1.size() && j < arr2.size()){
        if (arr1[i] <= arr2[j]){
            merged.push_back(arr1[i]);
            i += 1;
        } else {
            merged.push_back(arr2[j]);
            j += 1;
            ans += arr1.size() - i;
        }
    }

    while (i < arr1.size()) {
        merged.push_back(arr1[i]);
        i += 1;
    }
    while (j < arr2.size()) {
        merged.push_back(arr2[j]);
        j += 1;
    }

    return merged;
}


int main()
{
    int n;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    merge(leftHalf(arr), rightHalf(arr));
    cout << ans << endl;
    return 0;
}
