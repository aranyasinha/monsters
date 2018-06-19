#include <rapidjson/filereadstream.h>
#include <cstdio>

int load() {
  // Prepare JSON reader and input stream.
  rapidjson::Reader reader;
  char readBuffer[65536];
  FILE* fp = fopen("../assets/pokemon.json", "r");
  rapidjson::FileReadStream is(fp, readBuffer, sizeof(readBuffer));
  rapidjson::Document d;
  d.ParseStream(is);
  fclose(fp);

  printf("name = %s\n", d["name"].GetString());
  printf("hp = %d\n", document["hp"].GetInt());
  printf("physical attack = %d\n", d["ph_attack"].GetInt());
  printf("special attack = %d\n", document["sp_attack"].GetInt());
  printf("physical defense = %d\n", document["ph_defense"].GetInt());
  printf("special defense = %d\n", document["sp_defense"].GetInt());
  printf("speed = %d\n", document["speed"].GetInt());

  // Using a reference for consecutive access is handy and faster.
  const Value& a = document["type"];
  //assert(a.IsArray());
  for (SizeType i = 0; i < a.Size(); i++){ // Uses SizeType instead of size_t
    printf("a[%d] = %s\n", i, a[i].GetString());
  }
  //printf("type = %s\n", document["type"].Get());
}

/*
#include <rapidjson/document.h>
#include <rapidjson/istreamwrapper.h>
#include <fstream>

int load(){

  std::ifstream ifs("../assets/pokemon.json");
  rapidjson::IStreamWrapper isw(ifs);
  rapidjson::Document d;
  d.ParseStream(isw);
}
*/
