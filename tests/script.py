import os
import time

headers = ["color","director_name","num_critic_for_reviews","duration","director_facebook_likes","actor_3_facebook_likes","actor_2_name","actor_1_facebook_likes","gross","genres","actor_1_name","movie_title","num_voted_users","cast_total_facebook_likes","actor_3_name","facenumber_in_poster","plot_keywords","movie_imdb_link","num_user_for_reviews","language","country","content_rating","budget","title_year","actor_2_facebook_likes","imdb_score","aspect_ratio","movie_facebook_likes"]

compile_code = "gcc -o simpleCSVsorter simpleCSVsorter.c"

os.system(compile_code)

time.sleep(0.3)

for index,value in enumerate(headers,0):
    # print(index,value)
    command = "cat movie_metadata.csv | ./simpleCSVsorter -c {column_name}  > outputs/{index}.csv".format(column_name=value,index=index)
    time.sleep(0.2)
    # print(command)
    os.system(command)
    print("Finished {}".format(value))

print("Finished Testing ...")