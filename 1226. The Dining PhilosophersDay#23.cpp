/*java file*/

class DiningPhilosophers {

    public DiningPhilosophers() {
        
    }

    // call the run() method of any runnable to execute its code
    public void wantsToEat(int philosopher,
                           Runnable pickLeftFork,
                           Runnable pickRightFork,
                           Runnable eat,
                           Runnable putLeftFork,
                           Runnable putRightFork) throws InterruptedException {
        
        synchronized(this) {
            pickLeftFork.run();
            pickRightFork.run();
            eat.run();
            putLeftFork.run();
            putRightFork.run();
        }
    }
}

/*cpp file*/
 mutex mtx;//A mutex is a lockable object that is designed to signal when critical 
//sections of code need exclusive access, preventing other threads with 
//the same protection from executing concurrently and access the same memory locations.
public:
    DiningPhilosophers() {
       
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) 
    {
		mtx.lock();
        
        pickLeftFork();
        pickRightFork();
        eat();
        putLeftFork();
        putRightFork();
        
        mtx.unlock();
    }
