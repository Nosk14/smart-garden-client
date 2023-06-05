void mqtt_connect(const char* host);

bool mqtt_connected();

void mqtt_disconnect();

void mqtt_publish(const char* topic, const char* payload);