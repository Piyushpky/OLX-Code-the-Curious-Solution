#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
struct trieNode{
    int data;
    struct trieNode * a[102];
    int count;
};
struct trieNode *head=NULL;
void sell(){
    int d,p_id,c_id=0,s_id,r_id=0;
    cin>>d;
    cin>>p_id;
    char x;
    x=getchar();
    if(x=='.'){
        cin>>c_id;
    }
    cin>>s_id;
    char y;
    y=getchar();
    if(y=='.'){
        cin>>r_id;
    }
    struct  trieNode *p=head;
    //date
    struct trieNode *ptr=(struct trieNode*)malloc(sizeof(struct trieNode));
    ptr->data=d;
    for(int i=0;i<101;i++){
        ptr->a[i]=NULL;
    }
    ptr->count=0;

    if(p->a[d]==NULL){
        p->a[d]=ptr;
        p->count++;
        p=p->a[d];
    }else{
        //cout<<"p count is in else pehle"<<p->count<<endl;
        p->count++;
        p=p->a[d];
    }
    ptr=(struct trieNode*)malloc(sizeof(struct trieNode));
    ptr->data=p_id;
    ptr->count=0;
    for(int i=0;i<101;i++){
        ptr->a[i]=NULL;
    }
    if(p->a[p_id]==NULL){
        p->count++;
        p->a[p_id]=ptr;
        p=p->a[p_id];
    }else{
        p->count++;
        p=p->a[p_id];
    }
    ptr=(struct trieNode*)malloc(sizeof(struct trieNode));
    ptr->data=c_id;
    ptr->count=0;
    for(int i=0;i<101;i++){
        ptr->a[i]=NULL;
    }    

    if(p->a[c_id]==NULL){
        p->count++;
        p->a[c_id]=ptr;
        p=p->a[c_id];
    }else{
        p->count++;
        p=p->a[c_id];
    }
    ptr=(struct trieNode*)malloc(sizeof(struct trieNode));
    ptr->data=s_id;
    ptr->count=0;
    for(int i=0;i<101;i++){
        ptr->a[i]=NULL;
    }
    if(p->a[s_id]==NULL){
        p->count++;
        p->a[s_id]=ptr;
        p=p->a[s_id];
    }else{
        p->count++;
        p=p->a[s_id];
    }
    ptr=(struct trieNode*)malloc(sizeof(struct trieNode));
    ptr->data=r_id;
    ptr->count=1;
    for(int i=0;i<101;i++){
        ptr->a[i]=NULL;
    }
    if(p->a[r_id]==NULL){
        p->count++;
        p->a[r_id]=ptr;
        p=p->a[r_id];
    }else{
        p->count++;
        p=p->a[r_id];
        p->count++;
    }

}
int query(){
    int d_start,d_end=0,p_id,c_id=0,s_id,r_id=0;
    cin>>d_start;
    char w;
    w=getchar();
    if(w=='.'){
        cin>>d_end;
    }
    cin>>p_id;
    char x;
    x=getchar();
    if(x=='.'){
        cin>>c_id;
    }
    cin>>s_id;
    char y;
    y=getchar();
    if(y=='.'){
        cin>>r_id;
    }
    struct trieNode *p=head;
    if(d_end==0){
        //single case
        if(p_id==-1&&s_id==-1){
            if(p->a[d_start]==NULL){
                //   cout<<"head is null\n";
                return 0;
            }else{
                p=p->a[d_start];
                return p->count;
            }
        }else if(s_id==-1){
            if(p->a[d_start]==NULL){
                return 0;
            }else{
                p=p->a[d_start];
                if(c_id==0){
                    if(p->a[p_id]==NULL){
                        return 0;
                    }else{
                        p=p->a[p_id];
                        return p->count;
                    }
                }else{
                    if(p->a[p_id]==NULL){
                        return 0;
                    }else{
                        p=p->a[p_id];
                        if(p->a[c_id]==NULL){
                            return 0;
                        }else{
                            p=p->a[c_id];
                            return p->count;
                        }

                    }
                }
            }
        }else if(p_id==-1){
            int c=0;
            if(p->a[d_start]==NULL){
                return 0;
            }else{
                p=p->a[d_start];
                for(int i=0;i<101;i++){
                    if(p->a[i]!=NULL){
                        struct trieNode *pt=p;
                        pt=pt->a[i];
                        for(int j=0;j<101;j++){
                            if(pt->a[j]!=NULL){
                                struct trieNode *ip=pt;
                                ip=ip->a[j];
                                if(r_id==0){
                                    if(ip->a[s_id]!=NULL){
                                        c+=ip->a[s_id]->count;
                                        continue;
                                    }
                                }else{
                                    if(ip->a[s_id]!=NULL){
                                        ip=ip->a[s_id];
                                        if(ip->a[r_id]!=NULL){
                                            c+=ip->a[r_id]->count;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            return c;
        }else{
            if(p->a[d_start]==NULL){
                return 0;
            }else{
                p=p->a[d_start];
                if(p->a[p_id]==NULL){
                    return 0;
                }else{
                    p=p->a[p_id];
                    if(c_id!=0){
                        if(p->a[c_id]==NULL){
                            return 0;
                        }else{
                            p=p->a[c_id];
                            if(p->a[s_id]==NULL){
                                return 0;
                            }else{
                                p=p->a[s_id];
                                if(r_id==0){
                                    return p->count;
                                }else{
                                    if(p->a[r_id]==NULL){
                                        return 0;
                                    }else{
                                        return p->a[r_id]->count;
                                    }
                                }
                            }
                        }
                    }else{
                        int c=0;
                        struct trieNode *pt=p;
                        for(int j=0;j<101;j++){
                            if(pt->a[j]!=NULL){
                                struct trieNode *ip=pt;
                                ip=ip->a[j];
                                if(r_id==0){
                                    if(ip->a[s_id]!=NULL){
                                        c+=ip->a[s_id]->count;
                                        continue;
                                    }
                                }else{
                                    if(ip->a[s_id]!=NULL){
                                        ip=ip->a[s_id];
                                        if(ip->a[r_id]!=NULL){
                                            c+=ip->a[r_id]->count;
                                        }
                                    }
                                }
                            }
                        }
                        return c;
                    }
                }

            }
        }
    }else{
        int count=0;
        for(int i=d_start;i<=d_end;i++){
            struct trieNode *p=head;
            d_start=i;
            //single case
            if(p_id==-1&&s_id==-1){
                if(p->a[d_start]==NULL){
                    count+=0;
                }else{
                    p=p->a[d_start];
                    count+=p->count;
                }
            }else if(s_id==-1){
                if(p->a[d_start]==NULL){
                    count+=0;
                }else{
                    p=p->a[d_start];
                    if(c_id==0){
                        if(p->a[p_id]==NULL){
                            count+=0;
                        }else{
                            p=p->a[p_id];
                            count+=p->count;
                        }
                    }else{
                        if(p->a[p_id]==NULL){
                            count+=0;
                        }else{
                            p=p->a[p_id];
                            if(p->a[c_id]==NULL){
                                count+=0;
                            }else{
                                p=p->a[c_id];
                                count+=p->count;
                            }

                        }
                    }
                }
            }else if(p_id==-1){
                int c=0;
                if(p->a[d_start]==NULL){
                    count+=0;
                }else{
                    p=p->a[d_start];
                    for(int i=0;i<101;i++){
                        if(p->a[i]!=NULL){
                            struct trieNode *pt=p;
                            pt=pt->a[i];
                            for(int j=0;j<101;j++){
                                if(pt->a[j]!=NULL){
                                    struct trieNode *ip=pt;
                                    ip=ip->a[j];
                                    if(r_id==0){
                                        if(ip->a[s_id]!=NULL){
                                            c+=ip->a[s_id]->count;
                                            continue;
                                        }
                                    }else{
                                        if(ip->a[s_id]!=NULL){
                                            ip=ip->a[s_id];
                                            if(ip->a[r_id]!=NULL){
                                                c+=ip->a[r_id]->count;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                count+=c;
            }else{
                if(p->a[d_start]==NULL){
                    count+= 0;
                }else{
                    p=p->a[d_start];
                    if(p->a[p_id]==NULL){
                        count+=0;
                    }else{
                        p=p->a[p_id];
                        if(c_id!=0){
                            if(p->a[c_id]==NULL){
                                count+=0;
                            }else{
                                p=p->a[c_id];
                                if(p->a[s_id]==NULL){
                                    count+=0;
                                }else{
                                    p=p->a[s_id];
                                    if(r_id==0){
                                        count+=p->count;
                                    }else{
                                        if(p->a[r_id]==NULL){
                                            count+=0;
                                        }else{
                                            count+=p->a[r_id]->count;
                                        }
                                    }
                                }
                            }
                        }else{
                            int c=0;
                            struct trieNode *pt=p;
                            for(int j=0;j<101;j++){
                                if(pt->a[j]!=NULL){
                                    struct trieNode *ip=pt;
                                    ip=ip->a[j];
                                    if(r_id==0){
                                        if(ip->a[s_id]!=NULL){
                                            c+=ip->a[s_id]->count;
                                            continue;
                                        }
                                    }else{
                                        if(ip->a[s_id]!=NULL){
                                            ip=ip->a[s_id];
                                            if(ip->a[r_id]!=NULL){
                                                c+=ip->a[r_id]->count;
                                            }
                                        }
                                    }
                                }
                            }
                            count+=c;
                        }
                    }

                }
            }

        }
        return count;
    }
    
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin>>t;
    head=(struct trieNode*)malloc(sizeof(struct trieNode));
    head->count=1;
    while(t--){
        string s;
        cin>>s;
        
        if(s[0]=='S'){
            sell();
        }else{
            cout<<query()<<endl;
        }
    }
    return 0;
}
