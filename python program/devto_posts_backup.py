# USAGE:
# python devto_posts_backup.py [username]

import requests
import os
import sys

if len(sys.argv) > 2:
    print("Please only call me with one parameter")
    sys.exit()

params = {
     'username': sys.argv[1]
}

result = requests.get('https://dev.to/api/articles', params=params)
articles = result.json()

username = params['username']
posts_path = os.path.join(sys.path[0], 'dev.to', username, 'posts')
if not os.path.exists(posts_path):
    os.makedirs(posts_path)

for article in articles:
    slug = article['slug']
    article_id = article['id']
    filename = f'{slug}.md'

    article_result = requests.get(f'https://dev.to/api/articles/{article_id}')
    article = article_result.json()

    f = open(os.path.join(posts_path, filename), "w+", encoding="utf-8")
    f.write(article['body_markdown'])
    f.close()
