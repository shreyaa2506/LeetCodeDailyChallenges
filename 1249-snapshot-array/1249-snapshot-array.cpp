class SnapshotArray {
public:
    vector<map<int,int>>array;
    int snap_id;
public:
    
    SnapshotArray(int length) {
        array.resize(length);
        for(auto &history:array){
            history[0]=0;
        }
        snap_id=0;
    }
    
    
    void set(int index, int val) {
        array[index][snap_id]=val;
    }
    
    int snap() {
        return snap_id++;

    }
    
    int get(int index, int snap_id) {
        auto &history = array[index];
        auto it = history.upper_bound(snap_id);
        return (--it)->second;   }
    
    
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */