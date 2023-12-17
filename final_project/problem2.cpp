/**
 * @file problem2.cpp
 * @author Charis Liao (charisliao@berkeley.edu)
 * @brief 
 * @version 0.1
 * @date 2023-12-08
 * 
 * @copyright Copyright (c) 2023
 * 
 */

// PROBLEM 2 PROMT:
// You work for a company that creates a process where n jobs have to be
// sequenced. Let's number these jobs from 0 to n-1. There are dependencies
// between these jobs, that is some jobs must be completed before other jobs can
// be started. The parameters to this problem are: n: the number of jobs, then
// for every job: a tuple t(i,j) that species that job i depends on job j. In other
// words, job(j) must be completed before job(i) can be started. There may be
// more that one tuple or dependency relationship for any given job, that is a job
// may have more than one dependency. Your task is to write a progam to sched-
// ule the execution of these jobs. In case of a tie, choose any jobs in the tie arbi-
// trarily.

// HINT: For each job i build a queue of jobs that depend on it, that is, jobs
// that must be scheduled after job i. Then, for each job, count the number
// of dependencies that job has. Then, create a queue the ready queue that
// contains all jobs that have no dependencies. Select one job from this queue,
// this is the current or active job, and remove 1 dependency from every job
// that depends on this job. You can also delete this job. When the dependecy
// count for any given job reaches 0, add that job to the ready queue. Proceed
// until all jobs are executed. A tuple of the form (i,i) indicates that the job
// has no dependencies.

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// struct to store the job number and the number of dependencies
struct Job {
    int job_num;
    int num_dependencies;
    bool processed;
};

// function to schedule the execution of the jobs
//  and print job numbers in the order they are executed
void scheduleJobs(vector<vector<int>> dependencies) {
    // create a vector of jobs
    vector<Job> jobs;
    for (int i = 0; i < dependencies.size(); i++) {
        Job job;
        job.job_num = i;
        job.num_dependencies = dependencies[i].size();
        job.processed = false;
        jobs.push_back(job);
    }

    // create a queue of jobs that have no dependencies
    queue<Job> ready_queue;
    for (int i = 0; i < jobs.size(); i++) {
        if (jobs[i].num_dependencies == 0) {
            ready_queue.push(jobs[i]);
        }
    }

    // schedule the execution of the jobs
    while (!ready_queue.empty()) {
        // select one job from the ready queue
        Job active_job = ready_queue.front();
        ready_queue.pop();

        // print the job number
        cout << active_job.job_num << " ";

        active_job.processed = true;
        // remove 1 dependency from every job that depends on this job
        for (int i = 0; i < jobs.size(); i++) {
            for (int j = 0; j < dependencies[i].size(); j++) {
                if (dependencies[i][j] == active_job.job_num && !jobs[i].processed) {
                    jobs[i].num_dependencies--;

                    if (jobs[i].num_dependencies == 0) {
                        ready_queue.push(jobs[i]);
                    }
                }
            }
        }

        // // delete this job
        // jobs[active_job.job_num].num_dependencies = -1;

        // // when the dependency count for any given job reaches 0, add that job to the ready queue
        // for (int i = 0; i < jobs.size(); i++) {
        //     if (jobs[i].num_dependencies == 0) {
        //         ready_queue.push(jobs[i]);
        //     }
        // }
    }
    cout << endl;
    
}

int main() {
    // create a vector of vectors to store the dependencies
    vector<vector<int>> dependencies;
    vector<int> job0 = {1, 2};
    vector<int> job1 = {3};
    vector<int> job2 = {3};
    vector<int> job3 = {4};
    vector<int> job4 = {};
    dependencies.push_back(job0);
    dependencies.push_back(job1);
    dependencies.push_back(job2);
    dependencies.push_back(job3);
    dependencies.push_back(job4);

    // vector<vector<int>> dependencies;
    // vector<int> job0 = {};
    // vector<int> job1 = {0};
    // vector<int> job2 = {1};
    // vector<int> job3 = {1};
    // vector<int> job4 = {2, 3};
    // dependencies.push_back(job0);
    // dependencies.push_back(job1);
    // dependencies.push_back(job2);
    // dependencies.push_back(job3);
    // dependencies.push_back(job4);

    

    // schedule the execution of the jobs
    scheduleJobs(dependencies);

    return 0;
}

