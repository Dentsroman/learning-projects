package helpers;

import org.yaml.snakeyaml.Yaml;
import java.io.InputStream;
import java.util.Map;

public class YMLReader {
    public Map<String, Object> config(String filePath) {
        Yaml yaml = new Yaml();
        try (InputStream in = getClass().getClassLoader().getResourceAsStream(filePath)) {
            if (in == null) {
                throw new IllegalArgumentException("File not found: " + filePath);
            }
            return yaml.load(in);
        } catch (Exception e) {
            e.printStackTrace();
            return null;
        }
    }
}
